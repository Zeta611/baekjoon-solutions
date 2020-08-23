let fact_q_count n q =
  let rec iter t acc =
    if t > n then acc else
      iter (t * q) (acc + n / t)
  in
  iter q 0

let n_choose_m_q_count n m q =
  fact_q_count n q - fact_q_count m q - fact_q_count (n - m) q

let n_choose_m_10_count n m =
  min (n_choose_m_q_count n m 2) (n_choose_m_q_count n m 5)

let a, b = Scanf.scanf "%d %d" (fun a b -> a, b)
let () = Printf.printf "%d\n" (n_choose_m_10_count a b)
