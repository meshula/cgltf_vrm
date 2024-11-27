# :kimono: cgltf_vrm

**Single-file C99 VRM 1.0 loader companion to [cgltf](https://github.com/jkuhlmann/cgltf).** 

![Stage: alpha](https://img.shields.io/badge/-alpha-red)

_This library depends on cgltf.h to work (tested against v1.14)._

#### Extensions support

- [x] KHR_materials_unlit (*via cgltf*),
- [x] KHR_texture_transform (*via cgltf*),
- [x] KHR_materials_emissive_strength (*via cgltf*),
- [x] [VRMC_vrm](https://github.com/vrm-c/vrm-specification/tree/master/specification/VRMC_vrm-1.0),
- [x] [VRMC_springBone](https://github.com/vrm-c/vrm-specification/tree/master/specification/VRMC_springBone-1.0),
- [x] [VRMC_node_constraint](https://github.com/vrm-c/vrm-specification/tree/master/specification/VRMC_node_constraint-1.0),
- [x] [VRMC_materials_mtoon](https://github.com/vrm-c/vrm-specification/tree/master/specification/VRMC_materials_mtoon-1.0),
- [ ] [VRMC_VRM_animation](https://github.com/vrm-c/vrm-specification/tree/master/specification/VRMC_vrm_animation-1.0),
- [ ] [VRMC_springBone_extended_collider](https://github.com/vrm-c/vrm-specification/tree/master/specification/VRMC_springBone_extended_collider-1.0)

#### Basic usage

The main concern is to include the `cgltf_vrm` implementation in the same file and **_after_**
the `cgltf` implementation as it depends on some of its static functions to work.

##### Loading from an existing `cgltf_data` object
```c
#include <stdlib.h>

#define CGLTF_IMPLEMENTATION
#include "cgltf.h"
#include "cgltf_vrm.h"

int main(int argc, char **argv[])
{
  cgltf_options options{};
  cgltf_result result{};
  cgltf_data* gltf = NULL;
  cgltf_vrm_data vrm;

  result = cgltf_parse_file(&options, "avatar.vrm", &gltf);
  if (result != cgltf_result_success)
  {
    return EXIT_FAILURE;
  }

  result = cgltf_vrm_parse_cgltf_data(&options, gltf, &vrm);
  if (result != cgltf_result_success)
  {
    cgltf_free(gltf);
    return EXIT_FAILURE;
  }

  /* process data here */

  cgltf_vrm_free(&vrm);
  cgltf_free(gltf);

  return EXIT_SUCCESS;
}
```

<!-- 
##### Loading from a file
```c
#include <stdlib.h>

#define CGLTF_IMPLEMENTATION
#include "cgltf_vrm.h"

int main(int argc, char **argv[])
{
  cgltf_options options{};
  cgltf_result result{};

  cgltf_vrm_data* vrm = NULL;

  result = cgltf_vrm_parse_file(&options, "avatar.vrm", &vrm);
  if (result != cgltf_result_success)
  {
    return EXIT_FAILURE;
  }

  /* process data here */

  cgltf_vrm_free(&vrm);

  return EXIT_SUCCESS;
}
```
-->

### See also

* [VRM specifications](https://github.com/vrm-c/vrm-specification)
* [Unity implementation](https://github.com/vrm-c/UniVRM)
* [ThreeJS implementation](https://github.com/pixiv/three-vrm/tree/dev)
* [Online VRM viewer](https://vrm-viewer.ownverse.world/)

