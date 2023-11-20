#!/bin/sh

ARCH_NAME=""
SKIP_DIR=0
BASE_DIR="$HOME/!backup"

BACKUP_DIR="$BASE_DIR/`date +%Y.%m.%d`"

if ! test -d "$BACKUP_DIR" ; then
    echo "make directory $BACKUP_DIR"
    mkdir -p "$BACKUP_DIR"
fi

for DIR_NAME in * ; do
    if test -d "$DIR_NAME" ; then
        SKIP_DIR=0
        for SKIP_DIR_NAME in 'ccache' 'nix-data' 'pastgres-data' 'ubuntu-opt' ; do
            if [ "$SKIP_DIR_NAME" = "$DIR_NAME" ] ; then
                echo "skip $SKIP_DIR_NAME"
                SKIP_DIR=1
            fi
        done
        if [ $SKIP_DIR = 0 ] ; then
            ARCH_NAME="$DIR_NAME.tgz"
            echo "make archive $ARCH_NAME..."
            tar -czf "$ARCH_NAME" "$DIR_NAME"
            echo "move archive $ARCH_NAME to $BACKUP_DIR/$ARCH_NAME"
            mv "$ARCH_NAME" "$BACKUP_DIR"
        fi
    fi
done
