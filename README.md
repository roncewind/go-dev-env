# go-dev-env


## Run move inside docker container

```console
go run . --inputURL "file:///go/src/roncewind.git/move/bad_test.jsonl" --outputURL "amqp://guest:guest@192.168.6.76:5672"
```

## Run load inside docker container

```console
go run . --inputURL "amqp://guest:guest@192.168.6.76:5672"
```
