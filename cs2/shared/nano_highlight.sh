if [ ! -f ~/.nanorc ]; then

    cat /usr/share/nano/c.nanorc >> ~/.nanorc
    cat /usr/share/nano/sh.nanorc >> ~/.nanorc
    cat /usr/share/nano/xml.nanorc >> ~/.nanorc
    cat /usr/share/nano/makefile.nanorc >> ~/.nanorc
    cat /usr/share/nano/nanorc.nanorc >> ~/.nanorc

    echo "Enjoy a more colorful nano!"
else
    echo "You already have the config file in ~/.nanorc"
fi


