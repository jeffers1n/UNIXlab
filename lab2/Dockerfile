FROM ubuntu:latest

RUN apt-get update && apt-get install -y coreutils findutils

COPY script.sh /script.sh
RUN chmod +x /script.sh

VOLUME /shared

ENTRYPOINT ["/script.sh"]
