for input in *.in; do
    [[ -e "$input" ]] || continue# skip if no .in files match
 # echo "Testing $input:"
  #time ./NaturalSort < "$input" > "../out/${input%.in}.out"
   echo "Testing $input"
   { /usr/bin/time -f $'\nElapsed: %e s | User: %U s | System: %S s' 
      ./NaturalSort < "$input"; } > "../out/${input}.out" 2>&1 

  echo
  echo "Piped output to: ../out/${input%.in}.out"
  echo
done
