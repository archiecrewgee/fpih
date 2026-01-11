#!/bin/bash
set -eo pipefail

script_dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd $script_dir

# configuration - change as required
docker_tag=fpih-test:latest
dockerfile_dir=./test/

# rebuild docker if required
if [ -z "$(docker images $docker_tag -q)" ]; then
    echo "docker tag '$docker_tag' not found"
    echo "building dockerfile $dockerfile_dir with tag $docker_tag"
    docker build $dockerfile_dir -t $docker_tag
else
    echo "docker tag '$docker_tag' already exists"
fi

# build and execute tests in docker container
docker container run -v .:/code $docker_tag /bin/bash -c \
" \
cd /code/test && \
mkdir build -p && \
cmake . -B build -G \"Ninja\" && \
cmake --build build && \
./build/fpih-test \
" 
