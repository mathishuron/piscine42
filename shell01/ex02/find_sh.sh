find -name "*.sh" -printf '%f\n' | rev | cut -c 4- | rev
