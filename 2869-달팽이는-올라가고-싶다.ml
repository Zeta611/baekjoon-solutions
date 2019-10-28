exception Impossible

let split_on_char sep s =
  let r = ref [] in
  let j = ref (String.length s) in
  for i = String.length s - 1 downto 0 do
    if String.unsafe_get s i = sep then begin
      r := String.sub s (i + 1) (!j - i - 1) :: !r;
      j := i
    end
  done;
  String.sub s 0 !j :: !r

let split_by_space = split_on_char ' '

let solve = function
  | a::b::v::[] -> int_of_float (ceil (float (v - a) /. float (a - b))) + 1
  | _ -> raise Impossible

let line = List.map int_of_string (split_by_space (read_line ()))

let _ = print_int (solve line)
let _ = print_string "\n"
