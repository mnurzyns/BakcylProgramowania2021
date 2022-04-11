# BakcylProgramowania2021
Project created by trainees of Bakcyl Programowania in 2021.
siema

## Build steps
In project dir: 
```
docker-compose build
```

## Run steps
In project dir: 
```
xhost +local:$USER:root
docker-compose up -d
docker-compose run -it --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v /dev/dri/card0:/dev/dri/card0 bakcyl
```

## Clean project steps
In project dir:
```
docker-compose down
xhost -local:$USER:root
docker system prune -f
docker volume prune -f
docker image rm -f bakcylprogramowania2021_bakcyl:latest mysql:5.7
```