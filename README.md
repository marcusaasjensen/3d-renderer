# 🖼️ 3D Renderer in C++
A CPU-based 3D renderer written in C++, supporting simple primitive shapes and built entirely from scratch.

Upload the `.ppm` image file here to visualize the result: <href src="https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html">https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html</href>

---

Supports both **perspective** and **orthographic** projections.

Supports simple `.obj` imports (assets/teapot.obj).

> *Work in progress...*

## Example Scene Render (Perspective View)
<img style="width: 50%; height: auto;" alt="shaded" src="https://github.com/user-attachments/assets/15fdd5e6-cbb4-4707-b120-cd86f6e98816" /><img style="width: 50%; height: auto;" alt="zbuffer" src="https://github.com/user-attachments/assets/1a9db2a2-43a6-48d4-9f3b-e6f89d200de1" /><img style="width: 50%; height: auto;" alt="wireframe" src="https://github.com/user-attachments/assets/cd2f8b72-7aa9-4921-8a46-783a0146263f" /><img style="width: 50%; height: auto;" alt="shaded_wireframe" src="https://github.com/user-attachments/assets/715dda8d-4f4b-4e37-803c-a37a25b38923" />

## Rendering Pipeline Stages

- **Object Space (Local Space)**  
  Vertices are defined relative to each object's origin.  
  Example: A unit cube centered at (0,0,0).

- **World Space**  
  The object's local transform (position, rotation, scale) is applied.  
  All objects now share a common 3D world space.

- **Camera (View) Space**  
  The scene is transformed relative to the camera’s position and orientation.

- **Normalized Device Coordinates (NDC)**  
  All geometry is normalized into the range [-1, 1].

- **Screen Space**  
  NDC is mapped to 2D pixel coordinates on the canvas.

- **Rasterization**
  Z-Buffer precalculated and used for triangles rasterization.
  Vertices that are outside of the camera's view are ignored.
  Wireframe triangles are rasterized onto the canvas.
