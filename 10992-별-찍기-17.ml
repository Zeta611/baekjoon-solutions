let print_pyramid n =
  let rec print_spaces = function
    | 0 -> ()
    | n -> print_string " "; print_spaces (n - 1)
  in
  let rec print_stars = function
    | 0 -> ()
    | n -> print_string "*"; print_stars (n - 1)
  in
  let rec print_pyramid_top = function
    | 0 | 1 -> ()
    | m ->
      print_spaces (m - 1);
      print_string "*";
      print_spaces (2 * (n - m) + 1);
      print_string "*\n";
      print_pyramid_top (m - 1)
  in
  print_spaces n;
  print_string "*\n";
  print_pyramid_top n;
  if n > 0 then
    print_stars (n * 2 + 1);
    print_endline ""

let _ = print_pyramid (read_int () - 1)
