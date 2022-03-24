From pknagato4/bakcylprogramowania-base:1.0.0
 
Label maintainer="patryk.kaczmarek.ext@nokia.com"

ADD https://github.com/ufoscout/docker-compose-wait/releases/download/2.9.0/wait /wait
RUN chmod +x /wait

RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y \
      mysql-client \
      libqt5sql5-mysql \
      && rm -rf /var/lib/apt/lists/*

COPY . BakcylProgramowania2021/
RUN cmake -Bbakcyl-build -HBakcylProgramowania2021
RUN cmake --build bakcyl-build -j $(cat /proc/cpuinfo | grep processor | wc -l)

ENV DISPLAY :0

CMD /wait && \
    mysql -h db -u root < BakcylProgramowania2021/src/sql/database.sql && \
    cmake --build bakcyl-build --target BakcylProgramowania2021-run
