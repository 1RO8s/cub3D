#!/bin/bash
# dummy token
export ACTIONS_RUNTIME_TOKEN=fake-token
export GITHUB_TOKEN=fake-token

if [[ $1 == "dry" ]]; then
	# dryrun mode ( Only check workflow syntax )... does not docker run
	act -n --container-architecture linux/amd64
else
	# Flag to ensure compatibility (My PC chip is ARM, but may require x86_64(AMD64))
	act --container-architecture linux/amd64
	#act -j build --verbose --container-architecture linux/amd64 # debug
fi
