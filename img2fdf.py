from PIL import Image

def image_to_fdf(image_path, output_path, size=(70, 40), max_height=10):
    """
    Converts an image to a .fdf file based on brightness.

    Parameters:
    - image_path: Path to the input image file.
    - output_path: Path to the output .fdf file.
    - size: Tuple specifying the (width, height) to resize the image.
    - max_height: Maximum height value to scale the brightness.

    The function resizes the image, converts it to grayscale,
    and maps the brightness to integer height values for the .fdf file.
    """
    try:
        # Open the image and convert it to grayscale
        img = Image.open(image_path).convert('L')

        # Determine the appropriate resampling filter
        try:
            # For Pillow versions >= 9.1.0
            resample_filter = Image.Resampling.LANCZOS
        except AttributeError:
            # For older Pillow versions
            resample_filter = Image.LANCZOS

        # Resize the image to the specified size
        img = img.resize(size, resample=resample_filter)

        # Get the pixel data
        pixels = list(img.getdata())
        width, height = img.size

        # Open the output file for writing
        with open(output_path, 'w') as f:
            for y in range(height):
                # Extract the row of pixels
                row = pixels[y*width:(y+1)*width]
                # Map grayscale values (0-255) to height values (0-max_height)
                mapped_row = [str(int((pixel / 255) * max_height)) for pixel in row]
                # Write the mapped values to the file
                f.write(' '.join(mapped_row) + '\n')

        print(f"Successfully created {output_path} from {image_path}.")

    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
if __name__ == "__main__":
    # Replace 'your_image.png' with the path to your input image
    image_to_fdf('./io/logo3.png', './io/test_logo3.fdf')
