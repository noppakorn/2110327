// Hoping for rust in nattee grader one day
use std::{collections::BinaryHeap, io};
#[derive(Copy, Clone, PartialEq, Eq)]
struct Node {
    weight: i32,
    x: i32,
    y: i32,
}
impl Ord for Node {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other
            .weight
            .cmp(&self.weight)
            .then_with(|| self.x.cmp(&other.x))
            .then_with(|| self.y.cmp(&other.y))
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
    let v: Vec<i32> = s
        .trim()
        .split(" ")
        .map(|s| s.trim().parse().unwrap())
        .collect();
    let (r, c) = (v[0], v[1]);
    let mut g: Vec<Vec<i32>> = Vec::new();
    for _ in 0..r {
        s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        let v: Vec<i32> = s
            .trim()
            .split(" ")
            .map(|s| s.trim().parse().unwrap())
            .collect();
        g.push(v);
    }
    let direction = vec![(1, 0), (-1, 0), (0, 1), (0, -1)];
    let mut q = BinaryHeap::new();
    q.push(Node {
        weight: 0,
        x: 0,
        y: 0,
    });
    let mut d = vec![vec![1e9 as i32; c as usize]; r as usize];
    d[0][0] = 0;
    while let Some(Node { weight, x, y }) = q.pop() {
        for (dx, dy) in &direction {
            if x + dx < 0 || y + dy < 0 || x + dx >= r || y + dy >= c {
                continue;
            } else if weight + g[(x + dx) as usize][(y + dy) as usize]
                < d[(x + dx) as usize][(y + dy) as usize]
            {
                d[(x + dx) as usize][(y + dy) as usize] =
                    weight + g[(x + dx) as usize][(y + dy) as usize];
                q.push(Node {
                    weight: d[(x + dx) as usize][(y + dy) as usize],
                    x: x + dx,
                    y: y + dy,
                });
            }
        }
    }
    for i in d {
        for j in i {
            print!("{} ", j);
        }
        print!("\n");
    }
}