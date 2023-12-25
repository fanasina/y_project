#!/bin/bash

docker run --rm -it -w /ytest -e LD_LIBRARY_PATH=/ytest/ytest_t --mount type=bind,src="$(pwd)",target=/ytest ubuntu bash
