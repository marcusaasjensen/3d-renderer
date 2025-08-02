# 🖼️ 3D Renderer in C++
A CPU-based 3D wireframe renderer written in C++, supporting simple primitive shapes and built entirely from scratch.

Upload the `.ppm` image file here to visualize the result: <href src="https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html">https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html</href>

This renderer supports both **perspective** and **orthographic** projections.

> *Work in progress...*

## Example Scene Render (Perspective View)
<img style="width: 50%; height: auto;" alt="shaded" src="https://github.com/user-attachments/assets/1191260e-bf28-4ec7-a3df-f92570986f7a" /><img style="width: 50%; height: auto;" alt="wireframe" src="https://github.com/user-attachments/assets/a73584ff-527d-454d-83d2-5dbc32714848" /><img style="width: 50%; height: auto;" alt="zbuffer" src="https://github.com/user-attachments/assets/e4702892-a661-4dc9-a41b-5add50f579bc" /><img style="width: 50%; height: auto;" alt="shaded_wireframe" src="https://github.com/user-attachments/assets/657a2523-414e-4c65-8f95-28ba9ce53e3c" />

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
