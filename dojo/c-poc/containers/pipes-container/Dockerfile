FROM ubuntu:latest
COPY writer /writer
COPY reader /reader
RUN chmod +x /writer
RUN chmod +x /reader
CMD ["/bin/bash", "-c", "/writer | /reader"]

