From pknagato4/bakcylprogramowania-base:1.0.0
 
Label maintainer="patryk.kaczmarek.ext@nokia.com"

COPY . BakcylProgramowania2021/

RUN cmake -Bbakcyl-build -HBakcylProgramowania2021
RUN cmake --build bakcyl-build -j $(cat /proc/cpuinfo | grep processor | wc -l)

CMD cmake --build bakcyl-build --target BakcylProgramowania2021-run
