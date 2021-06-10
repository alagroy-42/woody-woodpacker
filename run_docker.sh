#!/bin/bash

docker build -t woody .
docker run -it --rm woody
