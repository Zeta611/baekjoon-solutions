let solve a b v = int_of_float (ceil (float (v - a) /. float (a - b))) + 1
let line = Scanf.scanf "%d %d %d" solve
let _ = print_int line
