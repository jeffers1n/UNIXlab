#!/bin/sh

container_id=$(hostname | cut -c1-7)

container_counter=1

stop_container() {
    echo "Остановка контейнера $container_id..."
    exit 0
}

trap 'stop_container' TERM INT

while true; do
    lock_file="/shared/.lock"
    exec 200>"$lock_file"
    flock 200

    existing_files=$(find /shared -maxdepth 1 -type f -name '[0-9][0-9][0-9]' 2>/dev/null)
    next_num=1
    while true; do
        formatted_num=$(printf "%03d" "$next_num")
        if ! echo "$existing_files" | grep -q "/shared/$formatted_num"; then
            break
        fi
        next_num=$((next_num + 1))
    done
    filename="/shared/$(printf "%03d" "$next_num")"

    echo "$container_id,$container_counter" > "$filename"

    flock -u 200
    exec 200>&-

    sleep 1

    rm -f "$filename"

    sleep 1

    container_counter=$((container_counter + 1))
done
