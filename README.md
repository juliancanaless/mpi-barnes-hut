# Barnes-Hut N-Body Simulation with MPI

This project implements the **Barnes–Hut algorithm** for the N‑body problem using **MPI** for distributed parallelism. The focus is learning **MPI**, **distributed computing methods**, and **programming for performance/speedup**.

---

## 📖 Overview
The N‑body problem models gravitational interactions among particles (e.g., stars/planets).
- **Naïve**: O(n²) all‑pairs interactions.
- **Barnes–Hut**: O(n log n) via a **quadtree** (2D) that approximates distant groups by their center of mass using a **Multipole Acceptance Criterion (MAC)**.
- Integration uses **Leapfrog–Verlet** for stable time stepping.

---

## ⚙️ Methods
- **Sequential**
  - Build quadtree → traverse with MAC to compute forces → update positions/velocities (Leapfrog–Verlet).
- **MPI Parallelization**
  - **Particle decomposition**: each rank updates a subset of particles.
  - Each rank builds a local Barnes–Hut tree from global particle data.
  - Exchange updated particles each step with **`MPI_Allgatherv`**.
- **Performance-Oriented Changes**
  - **Iterative (non‑recursive) traversal** to avoid stack overflows on large inputs.
  - **Inline center‑of‑mass updates** during insertion to skip a separate aggregation pass.

---

## 📊 Results (summary)
Tested particles: **10**, **100**, **100,000**; processes: **1–20**.

- **Small (10)**: Parallel slower (MPI overhead dominates).
- **Medium (100)**: Best ≈ **1.78×** speedup at **4 processes**; >4 degrades (comm overhead).
- **Large (100,000)**: Best ≈ **2.29×** at **4 processes**; plateaus ≈ **2.1–2.2×** beyond that.
- **Bottlenecks**: global tree construction per rank (Amdahl’s law), **`MPI_Allgatherv`** cost, and memory bandwidth contention.

---

## 🖥️ Running
1) Build:
   ~~~bash
   make
   ~~~
2) Run (MPI):
   ~~~bash
   mpirun -np <num_procs> ./barnes_hut <options>
   ~~~
**Options**
- `-s <steps>`: number of iterations  
- `-t <theta>`: MAC threshold (smaller → more accurate, slower)  
- `-d <dt>`: timestep  
- `-q`: run **sequential** implementation

---

## 🚀 Future Directions
- **Distributed tree construction** (each rank holds a partition; exchange summaries).
- **Spatial domain decomposition** to reduce communication.
- **Hybrid parallelism**: MPI + OpenMP/pthreads.

---

## 🔍 Takeaways
- Practical intro to **MPI** collectives and data distribution.
- Clear view of **compute vs. communication** trade‑offs.
- Parallel speedup can be capped by **global dependencies** and **collective costs**.
