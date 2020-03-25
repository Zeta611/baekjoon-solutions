let max_path triangle =
  let len = Array.length triangle in
  let memo = Array.make_matrix len len None in
  let subst i j v = memo.(i).(j) <- Some v; v in
  let rec loop i j =
    if i = len then 0 else
      match memo.(i).(j) with
      | Some v -> v
      | None ->
        subst i j (
          triangle.(i).(j) + max (loop (i + 1) j) (loop (i + 1) (j + 1))
        )
  in
  loop 0 0


let lines = read_int ()
let triangle =
  let rec loop i acc =
    if i = lines then acc else
      let line = read_line ()
        |> String.split_on_char ' '
        |> List.map int_of_string
        |> Array.of_list
      in
      loop (i + 1) (line :: acc)
  in
  Array.of_list (List.rev (loop 0 []))
let () = Printf.printf "%d\n" (max_path triangle)
