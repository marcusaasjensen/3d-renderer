# 🖼️ 3D Renderer in C++
A CPU-based 3D wireframe renderer written in C++, supporting simple primitive shapes and built entirely from scratch.

*Work in progress...*

## Example Scene Render (Perspective View)

<img width="1920" height="1080" alt="myScene" src="https://github.com/user-attachments/assets/fc6b9eeb-0710-4567-bd01-c2db6187dbd8" />

> **Note:** This renderer supports both **perspective** and **orthographic** projections.

## Rendering Pipeline Stages

- **Object Space (Local Space)**  
  Vertices are defined relative to each object's origin.  
  Example: A unit cube centered at (0,0,0).

- **World Space**  
  The object's local transform (position, rotation, scale) is applied.  
  All objects now share a common 3D world space.

- **Camera (View) Space**  
  The scene is transformed relative to the camera’s position and orientation.

- **Clip Space**  
  A projection matrix (perspective or orthographic) transforms 3D coordinates  
  into a canonical view volume.

- **Normalized Device Coordinates (NDC)**  
  The result of clip-space coordinates divided by W.  
  All geometry is normalized into the range [-1, 1].

- **Screen Space**  
  NDC is mapped to 2D pixel coordinates on the canvas.

- **Rasterization**  
  Wireframe triangles are rasterized onto the canvas.

- **Framebuffer / Output**  
  The canvas is saved to a `.ppm` image file (e.g., `output.ppm`).

