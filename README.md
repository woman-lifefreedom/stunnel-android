Things that should be done:

libtoolize (GNU libtool) 2.4.6

aclocal (GNU automake) 1.16.2

autoconf (GNU Autoconf) 2.69

automake (GNU automake) 1.16.2

install autoconf-archive
install g++-aarch64-linux-gnu

Build using ubuntu toolchain

First build openssl
```
export INSTALL_DIR=~/local-aarch64
../Configure linux-generic32 shared --prefix=$INSTALL_DIR --openssldir=$INSTALL_DIR/openssl --cross-compile-prefix=/usr/bin/aarch64-linux-gnu-
make
make install
```

Build stunnel

```
aclocal -I /usr/share/aclocal
automake --add-missing
autoconf -f
```

set $JAVA_HOME:
```
export JAVA_HOME=/usr/lib/jvm/default-java
../configure --with-ssl=$INSTALL_DIR --disable-silent-rules --host aarch64-linux-gnu
make
make install
```

```
$CC -shared -o ~/stunnel/libstunnel.so /root/stunnel/openssl/build-android/libssl.a /root/stunnel/openssl/build-android/libcrypto.a /root/stunnel/stunnel-android-2/build-android-2/src/.libs/libstunnel.a src/libstunnel_la-jnicalls.o
```
