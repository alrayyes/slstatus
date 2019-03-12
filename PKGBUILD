# Maintainer: Ryan Kes <alrayyes@gmail.com>

pkgname=slstatus-git
pkgver=r552.b14e039
pkgrel=1
pkgdesc='A status monitor for window managers'
arch=('i686' 'x86_64')
url='http://tools.suckless.org/slstatus'
depends=('libx11')
makedepends=('git')
license=('custom:ISC')

_patches=(
        "seperator-20180305-f4e35fa.diff"
        "backlight-20180305-85a4a18.diff"
        "ipv4-multiple-20190312-5f08c89.diff"
        )

source=("git+https://git.suckless.org/${pkgname%-git}"
        "config.h"
        "${_patches[@]}")

md5sums=('SKIP'
         'b52b327f7fdf0432e798e79b410fc2ed'
         '24ea93ef665decc0315248f62aa65f44'
         '58404d0af1893f560926daf605a79919'
         'fc9b31ea31470b6816f1f92c6bc6fa9d')

pkgver() {
    cd "${pkgname%-git}"
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}


prepare() {
  cd "${pkgname%-git}"

  for patch in "${_patches[@]}"; do
    echo "Applying patch $(basename $patch)..."
    patch -Np1 -i "$srcdir/$(basename $patch)"
  done

  cp $srcdir/config.h config.h
}

build() {
    cd "${pkgname%-git}"
    make X11INC='/usr/include/X11' X11LIB='/usr/lib/X11'
}

package() {
    cd "${pkgname%-git}"
    make DESTDIR="${pkgdir}" PREFIX='/usr/' install

    install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname%-git}/LICENSE"
}
