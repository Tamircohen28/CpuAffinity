# CPU Affinity
POC of setting cpu core the process.

build using `make build`.
run example using `make run`.

make sure child process has 'CAP_SYS_NICE'.
Read more ar `sched_setaffinity(2)`.