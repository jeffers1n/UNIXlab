#!/bin/sh

IMAGE_NAME="file-manager"
VOLUME_NAME="shared_volume"

# Остановка и удаление контейнеров
echo "Stopping containers..."
for container_id in $(docker ps -a -f "name=$IMAGE_NAME" --format "{{.ID}}"); do
    docker stop "$container_id" >/dev/null 2>&1 || true
    docker rm "$container_id" >/dev/null 2>&1 || true
done

# Удаление тома
if docker volume inspect "$VOLUME_NAME" >/dev/null 2>&1; then
    echo "Removing volume $VOLUME_NAME..."
    docker volume rm "$VOLUME_NAME" >/dev/null 2>&1 || true
fi
