find . -type f -iname "*.sh" -printf "%f\n" | rev |cut -c 4- |rev
