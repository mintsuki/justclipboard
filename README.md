justclipboard
======

Bullshit-free clipboard manager.

### What is justclipboard?

I was tired of all the bloaty feature-packed clipboard managers when I just wanted a way to
preserve a clipboard's contents after a program was closed.
`justclipboard` does exactly just that: holds the clipboard after a program has been closed
and nothing else.

### How to install?

You will need Qt development tools installed on your system.

Download this repo, enter it, then run:

```bash
mkdir build
cd build
cmake ..
make
sudo make install
```

### How to run?

Just run it. You can put it in your .xinitrc, or demonise it any other way. Possibilities
are endless.

For the best results run as your only clipboard manager.
