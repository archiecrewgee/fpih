set -eo pipefail

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

# run docker
docker container run $docker_tag echo "hello"

