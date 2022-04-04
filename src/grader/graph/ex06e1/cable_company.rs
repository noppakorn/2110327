use std::{collections::BinaryHeap, io};
#[derive(Copy, Clone, PartialEq, Eq)]
struct Node {
    weight: usize,
    vertex: usize,
}
impl Ord for Node {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other
            .weight
            .cmp(&self.weight)
            .then_with(|| self.vertex.cmp(&other.vertex))
    }
}
impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let n: usize = s.trim().parse().unwrap();
    let mut v: Vec<Vec<(usize, usize)>> = vec![Vec::new(); n];
    for i in 0..n - 1 {
        s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        let weight: Vec<usize> = s
            .trim()
            .split(" ")
            .map(|x| x.trim().parse().unwrap())
            .collect();
        for j in 0..weight.len() {
            v[i].push((j + i + 1, weight[j]));
            v[j + i + 1].push((i, weight[j]));
        }
    }
    let mut d: Vec<usize> = vec![1e9 as usize; n + 1];
    let mut in_mst = vec![false; n + 1];
    let mut heap = BinaryHeap::new();
    d[0] = 0;
    heap.push(Node {
        weight: 0,
        vertex: 0,
    });
    while let Some(Node { weight: _, vertex }) = heap.pop() {
        in_mst[vertex] = true;
        for (next_vertex, next_weight) in &v[vertex] {
            if !in_mst[*next_vertex] && next_weight < &d[*next_vertex] {
                d[*next_vertex] = *next_weight;
                heap.push(Node {
                    weight: *next_weight,
                    vertex: *next_vertex,
                });
            }
        }
    }
    println!(
        "{}",
        d.iter()
            .fold(0usize, |r, s| if *s != 1e9 as usize { r + s } else { r })
    );
}
