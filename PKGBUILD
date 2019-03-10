# Maintainer: Ankit R Gadiya <arch@argp.in>

pkgname=slstatus-git
pkgver=r552.b14e039
pkgrel=1
pkgdesc='A status monitor for window managers'
arch=('i686' 'x86_64')
url='http://tools.suckless.org/slstatus'
depends=('libx11' 'alsa-utils' 'xorg-xbacklight')
makedepends=('git')
license=('custom:ISC')

_patches=(
        "seperator-20180305-f4e35fa.diff"
        "backlight-20180305-85a4a18.diff"
        )

source=("git+https://git.suckless.org/${pkgname%-git}"
        "config.h"
        "${_patches[@]}")

md5sums=('SKIP'
         '9a36cf69d3a7318fffad5535f3e0fed5'
         '24ea93ef665decc0315248f62aa65f44'
         '58404d0af1893f560926daf605a79919')

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
