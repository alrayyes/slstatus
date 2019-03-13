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
        "seperator-20190305-f4e35fa.diff"
        "backlight-20190305-85a4a18.diff"
        "ipv4-multiple-20190312-5f08c89.diff"
        "netspeed-multiple-20190312-2ac86e1.diff"
        "combined_network-20190312-619ed9f.diff"
        )

source=("git+https://git.suckless.org/${pkgname%-git}"
        "config.h"
        "${_patches[@]}")

md5sums=('SKIP'
         '9916a68f1eb7904a24f72347091d11b9'
         '24ea93ef665decc0315248f62aa65f44'
         '58404d0af1893f560926daf605a79919'
         'fc9b31ea31470b6816f1f92c6bc6fa9d'
         '30f0a42ffc0e4f1e102ad2e3d1afe988'
         '865b046340744bc08c52170e0be78355')

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
