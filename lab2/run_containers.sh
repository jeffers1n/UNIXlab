#!/bin/sh

set -e

VOLUME_NAME="shared_volume"
IMAGE_NAME="file-manager"

# Создание тома
if ! docker volume inspect "$VOLUME_NAME" >/dev/null 2>&1; then
    echo "Creating volume $VOLUME_NAME..."
    docker volume create "$VOLUME_NAME"
fi

# Сборка образа
docker build -t "$IMAGE_NAME" .

# Запуск контейнеров
echo "Starting containers..."
i=1
while [ $i -le 10 ]; do
    docker run -d \
      --name "${IMAGE_NAME}_${i}" \
      -v "$VOLUME_NAME:/shared" \
      "$IMAGE_NAME"
    i=$((i + 1))
done
