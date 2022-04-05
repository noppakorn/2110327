use std::{collections::BinaryHeap, io};
#[derive(Copy, Clone, PartialEq, Eq)]
struct State {
    weight: usize,
    vertex: usize,
}
impl Ord for State {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other
            .weight
            .cmp(&self.weight)
            .then_with(|| self.vertex.cmp(&other.vertex))
    }
}
impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let v: Vec<usize> = s
        .trim()
        .split(' ')
        .map(|s| s.trim().parse().unwrap())
        .collect();
    let (n, m, _k) = (v[0], v[1], v[2]);

    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let start_server: Vec<usize> = s
        .trim()
        .split(' ')
        .map(|s| s.trim().parse().unwrap())
        .collect();

    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let c: Vec<usize> = s
        .trim()
        .split(' ')
        .map(|s| s.trim().parse().unwrap())
        .collect();

    let mut v: Vec<Vec<State>> = vec![vec![]; n];
    for _ in 0..m {
        s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        let tmp: Vec<usize> = s
            .trim()
            .split(' ')
            .map(|s| s.trim().parse().unwrap())
            .collect();
        v[tmp[0]].push(State {
            weight: c[tmp[1]],
            vertex: tmp[1],
        });
        v[tmp[1]].push(State {
            weight: c[tmp[0]],
            vertex: tmp[0],
        });
    }
    let mut pq: BinaryHeap<State> = BinaryHeap::new();
    let mut d: Vec<usize> = vec![1e9 as usize; n];
    for i in start_server {
        d[i] = c[i];
        pq.push(State {
            weight: c[i],
            vertex: i,
        })
    }
    while let Some(State { weight, vertex }) = pq.pop() {
        if weight != d[vertex] {
            continue;
        }
        for State {
            weight: next_weight,
            vertex: next_vertex,
        } in v[vertex].iter()
        {
            if weight + next_weight < d[*next_vertex] {
                d[*next_vertex] = weight + next_weight;
                pq.push(State {
                    weight: d[*next_vertex],
                    vertex: *next_vertex,
                })
            }
        }
    }
    println!("{}", d.iter().max().unwrap());
}