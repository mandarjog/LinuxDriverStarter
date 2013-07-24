VER=$(uname -r)
EXTRAVERSION=$(uname  -r | awk -F '-' '{printf "-%s-%s", $(NF-1), $NF}')

echo "Using EXTRAVERSION=${EXTRAVERSION}"

# EXTRAVERSION=-23-generic

CMD="apt-get source linux-image-${VER}"

WORKDIR=${1:?"working directory"}
echo "Use: ${CMD} "
echo "To get kernel source"

KERNELDIR=${2:?"kernel dir"}

WORKDIR=$(readlink -f ${WORKDIR})
KERNELDIR=$(readlink -f ${KERNELDIR})


