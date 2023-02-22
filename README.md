# go-dev-env


## Run move inside docker container

```console
go run . --inputURL "file:///go/src/roncewind.git/move/bad_test.jsonl" --outputURL "amqp://guest:guest@192.168.6.128:5672"
go run . --inputURL "file:///go/src/roncewind.git/move/loadtest-dataset-1M-with-datasource.jsonl" --outputURL "amqp://guest:guest@192.168.6.128:5672"
go run . --inputURL "file:///go/src/roncewind.git/move/loadtest-dataset-100.jsonl" --outputURL "amqp://guest:guest@192.168.6.128:5672"

go run . --inputURL "file:///go/src/move/loadtest-dataset-100.jsonl" --outputURL "amqp://guest:guest@Rons-MacBook-Pro.local"
```

## Run load inside docker container

```console
go run . --inputURL "amqp://guest:guest@192.168.6.128:5672"

go run . --inputURL "amqp://guest:guest@Rons-MacBook-Pro.local"
```

## scratch pad:

```
export SENZING_TOOLS_DATABASE_URL="sqlite3://na:na@/var/opt/senzing/sqlite/G2C.db"
search {"name_last": "Lovell", "name_first": "Devin", "date_of_birth": "1992-12-10"}
search {"DATE_OF_BIRTH": "1974-7-16", "NAME_LAST": "OBERMOELLER", "SOCIAL_HANDLE": "shuddersv"}
docker exec -it go-dev /bin/bash
docker run -it --rm --name go-dev --volume /home/roncewind/docktermj.git/:/go/src/docktermj.git --volume /home/roncewind/roncewind.git/:/go/src/roncewind.git roncewind/go-dev-env
hostname -I | awk '{print $1}'
docker run -it --rm --name rabbitmq -p 5672:5672 -p 15672:15672 rabbitmq:3.10-management

docker run -it --rm --name go-dev --volume /Users/roncewind/roncewind.git/:/go/src/ roncewind/go-dev-env

```