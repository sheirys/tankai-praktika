# Tanks game v0.1

[![GitHub license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/sheirys/tankai-praktika/blob/master/LICENSE.md)

Fun abandoned project - multipayer tanks game. It's still in pre-alpha stage and probably this is last version.

## Run server
Server is implemented in perl, so you are free to experiment. Just use `perl server.pl` to start server. Default port is `5151`. Edit `server.pl` file if you need other port.

## Game configuration
All configurations are in `options.txt` file. Default options are:

    0               <- some magic zero
    800             <- screen width
    600             <- screen height, so 800x600 window size
    127.0.0.1       <- server IP
    5151            <- port

## Compilation
As there is no `Makefile` now, use `g++ *.cpp -o main -lSDL -lSDL_net -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm`. Be sure that you have full `SDL-dev` stack.

[![Screenshot from 2016-10-31 19-39-55.png](https://s14.postimg.org/86qfkc09t/Screenshot_from_2016_10_31_19_39_55.png)](https://postimg.org/image/3kubbzeql/)
