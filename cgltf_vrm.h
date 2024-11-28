/**
 * cgltf_vrm - a single-file VRM 1.0 parser written in C99, extending cgltf.
 *
 * Version: 0.1
 *
 * Last modification: 2024/11
 *
 * Dependencies: cgltf.h (tested against v1.14).
 *
 * Distributed under the MIT License, see notice at the end of this file.
 *
 * Building:
 * Include this file where you need the struct and function
 * declarations. Have exactly one source file where you define
 * `CGLTF_IMPLEMENTATION` before including this file to get the
 * function definitions. This should be set in the same file as
 * the one containing cgltf's implementation.
 *
 */
#ifndef CGLTF_VRM_H_INCLUDED__
#define CGLTF_VRM_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(CGLTF_H_INCLUDED__)
#include "cgltf.h"
#endif

/* -------------------------------------------------------------------------- */
/* -- VRMC commons -- */

typedef enum cgltf_vrm_spec_version
{
  cgltf_vrm_spec_version_v_1_0,
  cgltf_vrm_spec_version_max_enum,
} cgltf_vrm_spec_version;

/* -------------------------------------------------------------------------- */
/* -- VRMC_vrm -- */


/* VRMC_vrm.humanoid */

typedef struct cgltf_vrm_humanoid_bone
{
  char* name;
  cgltf_node* node;
} cgltf_vrm_humanoid_bone;

typedef struct cgltf_vrm_humanoid
{
  cgltf_vrm_humanoid_bone* human_bones;
  cgltf_size human_bones_count;
} cgltf_vrm_humanoid;


/* VRMC_vrm.meta */

typedef enum cgltf_vrm_meta_avatar_permission_type
{
  cgltf_vrm_meta_avatar_permission_type_only_author,
  cgltf_vrm_meta_avatar_permission_type_only_separately_licensed_person,
  cgltf_vrm_meta_avatar_permission_type_everyone,
  cgltf_vrm_meta_avatar_permission_type_max_enum,
} cgltf_vrm_meta_avatar_permission_type;

typedef enum cgltf_vrm_meta_commercial_usage_type
{
  cgltf_vrm_meta_commercial_usage_type_personal_non_profit,
  cgltf_vrm_meta_commercial_usage_type_personal_profit,
  cgltf_vrm_meta_commercial_usage_type_corporation,
  cgltf_vrm_meta_commercial_usage_type_max_enum,
} cgltf_vrm_meta_commercial_usage_type;

typedef enum cgltf_vrm_meta_credit_notation_type
{
  cgltf_vrm_meta_credit_notation_type_required,
  cgltf_vrm_meta_credit_notation_type_unnecessary,
  cgltf_vrm_meta_credit_notation_type_max_enum,
} cgltf_vrm_meta_credit_notation_type;

typedef enum cgltf_vrm_meta_modification_type
{
  cgltf_vrm_meta_modification_type_prohibited,
  cgltf_vrm_meta_modification_type_allow_modification,
  cgltf_vrm_meta_modification_type_allow_modification_redistribution,
  cgltf_vrm_meta_modification_type_max_enum,
} cgltf_vrm_meta_modification_type;

typedef struct cgltf_vrm_meta
{
  char* name;
  char* version;

  char** authors;
  cgltf_size authors_count;

  char* license_url;
  char* copyright_information;
  char* contact_information;

  cgltf_bool has_thumbnail_image;
  cgltf_image* thumbnail_image;

  cgltf_vrm_meta_avatar_permission_type avatar_permission;
  cgltf_vrm_meta_commercial_usage_type commercial_usage;
  cgltf_vrm_meta_credit_notation_type credit_notation;
  cgltf_vrm_meta_modification_type modification;

  cgltf_bool allow_antisocial_or_hate_usage;
  cgltf_bool allow_excessively_sexual_usage;
  cgltf_bool allow_excessively_violent_usage;
  cgltf_bool allow_political_or_religious_usage;
  cgltf_bool allow_redistribution;
} cgltf_vrm_meta;


/* VRMC_vrm.firstPerson */

typedef enum cgltf_vrm_first_person_mesh_annotation_type
{
  cgltf_vrm_first_person_mesh_annotation_type_auto,
  cgltf_vrm_first_person_mesh_annotation_type_first_person_only,
  cgltf_vrm_first_person_mesh_annotation_type_third_person_only,
  cgltf_vrm_first_person_mesh_annotation_type_both,
  cgltf_vrm_first_person_mesh_annotation_type_max_enum,
} cgltf_vrm_first_person_mesh_annotation_type;

typedef struct cgltf_vrm_first_person_mesh_annotation
{
  cgltf_vrm_first_person_mesh_annotation_type type;
  cgltf_node* node;
} cgltf_vrm_first_person_mesh_annotation;

typedef struct cgltf_vrm_first_person
{
  cgltf_vrm_first_person_mesh_annotation* mesh_annotations;
  cgltf_size mesh_annotations_count;
} cgltf_vrm_first_person;


/* VRMC_vrm.expressions */

typedef enum cgltf_vrm_expression_override_type
{
  cgltf_vrm_expression_override_type_none,
  cgltf_vrm_expression_override_type_block,
  cgltf_vrm_expression_override_type_blend,
  cgltf_vrm_expression_override_type_max_enum,
} cgltf_vrm_expression_override_type;

typedef struct cgltf_vrm_expression_morph_target_bind
{
  cgltf_node* node;
  cgltf_int index;
  cgltf_float weight;
} cgltf_vrm_expression_morph_target_bind;

typedef enum cgltf_vrm_expression_material_color_bind_type
{
  cgltf_vrm_expression_material_color_bind_type_color,
  cgltf_vrm_expression_material_color_bind_type_uv_scale,
  cgltf_vrm_expression_material_color_bind_type_uv_offset,
  cgltf_vrm_expression_material_color_bind_type_max_enum,
} cgltf_vrm_expression_material_color_bind_type;

typedef struct cgltf_vrm_expression_material_color_bind
{
  cgltf_material* material;
  cgltf_vrm_expression_material_color_bind_type type;
  cgltf_float target_value[4];
} cgltf_vrm_expression_material_color_bind;

typedef struct cgltf_vrm_expression_texture_transform_bind
{
  cgltf_material* material;
  cgltf_float scale[2];
  cgltf_float offset[2];
} cgltf_vrm_expression_texture_transform_bind;

typedef struct cgltf_vrm_expression
{
  char* name;
  cgltf_bool is_binary;

  cgltf_vrm_expression_morph_target_bind* morph_target_binds;
  cgltf_size morph_target_binds_count;

  cgltf_vrm_expression_material_color_bind* material_color_binds;
  cgltf_size material_color_binds_count;

  cgltf_vrm_expression_texture_transform_bind* texture_transform_binds;
  cgltf_size texture_transform_binds_count;

  cgltf_vrm_expression_override_type override_blink;
  cgltf_vrm_expression_override_type override_look_at;
  cgltf_vrm_expression_override_type override_mouth;
} cgltf_vrm_expression;

typedef struct cgltf_vrm_expressions
{
  cgltf_vrm_expression* preset;
  cgltf_size preset_count;

  cgltf_vrm_expression* custom;
  cgltf_size custom_count;
} cgltf_vrm_expressions;


/* VRMC_vrm.lookAt */

typedef enum cgltf_vrm_look_at_type
{
  cgltf_vrm_look_at_type_bone,
  cgltf_vrm_look_at_type_expression,
  cgltf_vrm_look_at_type_max_enum,
} cgltf_vrm_look_at_type;

typedef struct cgltf_vrm_look_at_range_map
{
  cgltf_float input_max_value;
  cgltf_float output_scale;
} cgltf_vrm_look_at_range_map;

typedef struct cgltf_vrm_look_at
{
  cgltf_vrm_look_at_type type;
  cgltf_float offset_from_head_bone[3];
  cgltf_vrm_look_at_range_map range_map_horizontal_inner;
  cgltf_vrm_look_at_range_map range_map_horizontal_outer;
  cgltf_vrm_look_at_range_map range_map_vertical_up;
  cgltf_vrm_look_at_range_map range_map_vertical_down;
} cgltf_vrm_look_at;


/* VRMC_vrm */

typedef struct cgltf_vrm_core
{
  cgltf_vrm_spec_version spec_version;
  cgltf_vrm_humanoid humanoid;
  cgltf_vrm_meta meta;

  cgltf_bool has_first_person;
  cgltf_bool has_expressions;
  cgltf_bool has_look_at;

  cgltf_vrm_first_person first_person;
  cgltf_vrm_expressions expressions;
  cgltf_vrm_look_at look_at;
} cgltf_vrm_core;

/* -------------------------------------------------------------------------- */
/* -- VRMC_springBone -- */


/* VRMC_springBone.collider */

typedef enum cgltf_vrm_spring_bone_collider_shape {
  cgltf_vrm_spring_bone_collider_shape_sphere,
  cgltf_vrm_spring_bone_collider_shape_capsule,
  cgltf_vrm_spring_bone_collider_shape_max_enum,
} cgltf_vrm_spring_bone_collider_shape;

typedef struct cgltf_vrm_spring_bone_collider {
  cgltf_node* node;
  cgltf_vrm_spring_bone_collider_shape shape;
  cgltf_float offset[3];
  cgltf_float radius;
  cgltf_float tail[3];
} cgltf_vrm_spring_bone_collider;


/* VRMC_springBone.colliderGroup */

typedef struct cgltf_vrm_spring_bone_collider_group {
  char* name;
  cgltf_int* colliders;
  cgltf_size colliders_count;
} cgltf_vrm_spring_bone_collider_group;


/* VRMC_springBone.spring */

typedef struct cgltf_vrm_spring_bone_spring_joint {
  cgltf_node* node;
  cgltf_float hit_radius;
  cgltf_float stiffness;
  cgltf_float gravity_power;
  cgltf_float gravity_dir[3];
  cgltf_float drag_force;
} cgltf_vrm_spring_bone_spring_joint;

typedef struct cgltf_vrm_spring_bone_spring {
  char* name;

  cgltf_vrm_spring_bone_spring_joint* joints;
  cgltf_size joints_count;

  cgltf_int* collider_groups;
  cgltf_size collider_groups_count;

  cgltf_node* center;
} cgltf_vrm_spring_bone_spring;


/* VRMC_springBone */

typedef struct cgltf_vrm_spring_bone
{
  cgltf_vrm_spec_version spec_version;

  cgltf_vrm_spring_bone_collider* colliders;
  cgltf_size colliders_count;

  cgltf_vrm_spring_bone_collider_group* collider_groups;
  cgltf_size collider_groups_count;

  cgltf_vrm_spring_bone_spring* springs;
  cgltf_size springs_count;
} cgltf_vrm_spring_bone;

/* -------------------------------------------------------------------------- */
/* -- VRMC_node_constraint -- */

typedef enum cgltf_vrm_node_constraint_type
{
  cgltf_vrm_node_constraint_type_roll,
  cgltf_vrm_node_constraint_type_aim,
  cgltf_vrm_node_constraint_type_rotation,
  cgltf_vrm_node_constraint_type_max_enum,
} cgltf_vrm_node_constraint_type;

typedef enum cgltf_vrm_node_constraint_roll_axis
{
  cgltf_vrm_node_constraint_roll_axis_x,
  cgltf_vrm_node_constraint_roll_axis_y,
  cgltf_vrm_node_constraint_roll_axis_z,
  cgltf_vrm_node_constraint_roll_axis_max_enum,
} cgltf_vrm_node_constraint_roll_axis;

typedef enum cgltf_vrm_node_constraint_aim_axis
{
  cgltf_vrm_node_constraint_aim_axis_positive_x,
  cgltf_vrm_node_constraint_aim_axis_negative_x,
  cgltf_vrm_node_constraint_aim_axis_positive_y,
  cgltf_vrm_node_constraint_aim_axis_negative_y,
  cgltf_vrm_node_constraint_aim_axis_positive_z,
  cgltf_vrm_node_constraint_aim_axis_negative_z,
  cgltf_vrm_node_constraint_aim_axis_max_enum,
} cgltf_vrm_node_constraint_aim_axis;

typedef struct cgltf_vrm_node_constraint
{
  cgltf_vrm_spec_version spec_version;

  cgltf_vrm_node_constraint_type type;
  cgltf_node* source;
  cgltf_float weight;
  union cgltf_vrm_node_constraint_axis {
    cgltf_vrm_node_constraint_roll_axis roll;
    cgltf_vrm_node_constraint_aim_axis aim;
  } axis;
} cgltf_vrm_node_constraint;

/* -------------------------------------------------------------------------- */
/* -- VRMC_materials_mtoon -- */

typedef struct cgltf_vrm_mtoon_texture_info
{
  cgltf_int index;
  cgltf_int tex_coord;
} cgltf_vrm_mtoon_texture_info;

typedef struct cgltf_vrm_mtoon_shading_shift_texture_info
{
  cgltf_int index;
  cgltf_int tex_coord;
  cgltf_float scale;
} cgltf_vrm_mtoon_shading_shift_texture_info;

typedef enum cgltf_vrm_mtoon_outline_width_mode {
  cgltf_vrm_mtoon_outline_width_mode_none,
  cgltf_vrm_mtoon_outline_width_mode_world_coordinates,
  cgltf_vrm_mtoon_outline_width_mode_screen_coordinates,
  cgltf_vrm_mtoon_outline_width_mode_max_enum,
} cgltf_vrm_mtoon_outline_width_mode;

typedef struct cgltf_vrm_mtoon
{
  cgltf_vrm_spec_version spec_version;

  /* Rendering */
  cgltf_bool transparent_with_z_write;
  cgltf_int render_queue_offset_number;

  /* Shade Color */
  cgltf_float shade_color_factor[3];
  cgltf_vrm_mtoon_texture_info shade_multiply_texture;
  cgltf_float shading_shift_factor;
  cgltf_vrm_mtoon_shading_shift_texture_info shading_shift_texture;
  cgltf_float shading_toony_factor;

  /* Global Illumination */
  cgltf_float gi_equalization_factor;

  /* Rim Lighting */
  cgltf_float matcap_factor[3];
  cgltf_vrm_mtoon_texture_info matcap_texture;
  cgltf_float parametric_rim_color_factor[3];
  cgltf_float parametric_rim_fresnel_power_factor;
  cgltf_float parametric_rim_lift_factor;
  cgltf_vrm_mtoon_texture_info rim_multiply_texture;
  cgltf_float rim_lighting_mix_factor;

  /* Outline */
  cgltf_vrm_mtoon_outline_width_mode outline_width_mode;
  cgltf_float outline_width_factor;
  cgltf_vrm_mtoon_texture_info outline_width_multiply_texture;
  cgltf_float outline_color_factor[3];
  cgltf_float outline_lighting_mix_factor;

  /* UV Animation */
  cgltf_vrm_mtoon_texture_info uv_animation_mask_texture;
  cgltf_float uv_animation_scroll_x_speed_factor;
  cgltf_float uv_animation_scroll_y_speed_factor;
  cgltf_float uv_animation_rotation_speed_factor;
} cgltf_vrm_mtoon;

/* -------------------------------------------------------------------------- */

typedef struct cgltf_vrm_extended_node
{
  cgltf_bool has_node_constraint;
  cgltf_vrm_node_constraint node_constraint;

  /*cgltf_node const* node;*/
} cgltf_vrm_extended_node;

typedef struct cgltf_vrm_extended_material
{
  cgltf_bool has_mtoon;
  cgltf_vrm_mtoon mtoon;

  /*cgltf_material const* material;*/
} cgltf_vrm_extended_material;

typedef struct cgltf_vrm_data
{
  cgltf_vrm_core core;

  cgltf_vrm_spring_bone spring_bone;
  cgltf_bool has_spring_bone;

  cgltf_vrm_extended_node* extended_nodes;
  cgltf_size extended_nodes_count;

  cgltf_vrm_extended_material* extended_materials;
  cgltf_size extended_materials_count;

  cgltf_memory_options memory; /* tmp? */
  /*cgltf_data const* data;*/
} cgltf_vrm_data;

/* -------------------------------------------------------------------------- */

cgltf_result cgltf_vrm_parse_cgltf_data(cgltf_options const* options, cgltf_data const* gltf, cgltf_vrm_data* vrm);

/*cgltf_result cgltf_vrm_parse_file(cgltf_options const* options, char const* filename, cgltf_vrm_data** out_data);

cgltf_result cgltf_vrm_parse(cgltf_options const* options, void const* data, cgltf_size size, cgltf_vrm_data** out_data);*/

void cgltf_vrm_free(cgltf_vrm_data* vrm);

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* CGLTF_VRM_H_INCLUDED__ */

/* -------------------------------------------------------------------------- */

#if defined(__INTELLISENSE__) || defined(__JETBRAINS_IDE__)
#define CGLTF_IMPLEMENTATION
#endif

#ifdef CGLTF_IMPLEMENTATION

#define CGLTF_VRM_JSON_LOG(suffixTag) \
  fwrite((char*)json_chunk + tokens[i].start, 1, tokens[i].end - tokens[i].start, stderr); \
  fprintf(stderr, suffixTag "\n");

#define CGLTF_VRM_JSON_SKIP() \
  i = cgltf_skip_json(tokens, i+1);

#if defined(NDEBUG)
#define CGLTF_VRM_LOG_SKIPPED(prefixTag) \
  CGLTF_VRM_JSON_SKIP()
#else
#define CGLTF_VRM_LOG_SKIPPED(prefixTag) \
  fprintf(stderr, "%s", prefixTag); \
  CGLTF_VRM_JSON_LOG(" [skipped]") \
  CGLTF_VRM_JSON_SKIP()
#endif

#define CGLTF_VRM_RET_STRING_TYPE(typeBase, suffix) \
  if (cgltf_json_strcmp(tokens, json_chunk, #suffix) == 0) { return typeBase##suffix; }

static
cgltf_vrm_spec_version cgltf_vrm_string_to_spec_version(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_spec_version_, v_1_0)
  return cgltf_vrm_spec_version_max_enum;
}

static
cgltf_vrm_meta_avatar_permission_type cgltf_vrm_string_to_meta_avatar_permission(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_avatar_permission_type_, only_author)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_avatar_permission_type_, only_separately_licensed_person)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_avatar_permission_type_, everyone)
  return cgltf_vrm_meta_avatar_permission_type_max_enum;
}

static
cgltf_vrm_meta_commercial_usage_type cgltf_vrm_string_to_meta_commercial_usage(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_commercial_usage_type_, personal_non_profit)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_commercial_usage_type_, personal_profit)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_commercial_usage_type_, corporation)
  return cgltf_vrm_meta_commercial_usage_type_max_enum;
}

static
cgltf_vrm_meta_credit_notation_type cgltf_vrm_string_to_meta_credit_notation(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_credit_notation_type_, required)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_credit_notation_type_, unnecessary)
  return cgltf_vrm_meta_credit_notation_type_max_enum;
}

static
cgltf_vrm_meta_modification_type cgltf_vrm_string_to_meta_modification(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_modification_type_, prohibited)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_modification_type_, allow_modification)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_meta_modification_type_, allow_modification_redistribution)
  return cgltf_vrm_meta_modification_type_max_enum;
}

static
cgltf_vrm_first_person_mesh_annotation_type cgltf_vrm_string_to_first_person_mesh_annotation(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_first_person_mesh_annotation_type_, auto)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_first_person_mesh_annotation_type_, first_person_only)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_first_person_mesh_annotation_type_, third_person_only)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_first_person_mesh_annotation_type_, both)
  return cgltf_vrm_first_person_mesh_annotation_type_max_enum;
}

static
cgltf_vrm_expression_override_type cgltf_vrm_string_to_expression_override(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_expression_override_type_, none)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_expression_override_type_, block)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_expression_override_type_, blend)
  return cgltf_vrm_expression_override_type_max_enum;
}

static
cgltf_vrm_look_at_type cgltf_vrm_string_to_look_at(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_look_at_type_, bone)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_look_at_type_, expression)
  return cgltf_vrm_look_at_type_max_enum;
}

static
cgltf_vrm_spring_bone_collider_shape cgltf_vrm_string_to_spring_bone_collider_shape(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_spring_bone_collider_shape_, sphere)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_spring_bone_collider_shape_, capsule)
  return cgltf_vrm_spring_bone_collider_shape_max_enum;
}

static
cgltf_vrm_node_constraint_type cgltf_vrm_string_to_node_constraint_type(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_type_, roll)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_type_, aim)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_type_, rotation)
  return cgltf_vrm_node_constraint_type_max_enum;
}

static
cgltf_vrm_node_constraint_roll_axis cgltf_vrm_string_to_node_constraint_roll_axis(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_roll_axis_, x)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_roll_axis_, y)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_roll_axis_, z)
  return cgltf_vrm_node_constraint_roll_axis_max_enum;
}

static
cgltf_vrm_node_constraint_aim_axis cgltf_vrm_string_to_node_constraint_aim_axis(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_aim_axis_, positive_x)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_aim_axis_, positive_y)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_aim_axis_, positive_z)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_aim_axis_, negative_x)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_aim_axis_, negative_y)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_node_constraint_aim_axis_, negative_z)
  return cgltf_vrm_node_constraint_aim_axis_max_enum;
}

static
cgltf_vrm_mtoon_outline_width_mode cgltf_vrm_string_to_mtoon_outline_width_mode(jsmntok_t const* tokens, uint8_t const* json_chunk)
{
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_mtoon_outline_width_mode_, none)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_mtoon_outline_width_mode_, world_coordinates)
  CGLTF_VRM_RET_STRING_TYPE(cgltf_vrm_mtoon_outline_width_mode_, screen_coordinates)
  return cgltf_vrm_mtoon_outline_width_mode_max_enum;
}

/* ----------- VRMC_vrm ----------- */

static
int cgltf_vrm_parse_json_humanoid(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_humanoid* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);
  ++i;

  if (cgltf_json_strcmp(tokens + i, json_chunk, "humanBones") == 0)
  {
    ++i;
    out->human_bones_count = tokens[i].size;
    out->human_bones = (cgltf_vrm_humanoid_bone*)cgltf_calloc(options, sizeof(cgltf_vrm_humanoid_bone), out->human_bones_count);
    if (!out->human_bones)
    {
      return CGLTF_ERROR_NOMEM;
    }

    ++i;
    for (cgltf_size j = 0; j < out->human_bones_count; ++j)
    {
      cgltf_vrm_humanoid_bone *bone = &out->human_bones[j];

      CGLTF_CHECK_KEY(tokens[i]);
      i = cgltf_parse_json_string(options, tokens, i, json_chunk, &bone->name);

      i += 2;
      bone->node = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
      i = cgltf_skip_json(tokens, i);
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_meta(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_meta* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_meta));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens + i, json_chunk, "name") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->name);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "licenseUrl") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->license_url);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "authors") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(char*), (void**)&out->authors, &out->authors_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->authors_count; ++k)
      {
        i = cgltf_parse_json_string(options, tokens, i, json_chunk, &out->authors[k]);
        if (i < 0)
        {
          return i;
        }
      }
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "thumbnailImage") == 0)
    {
      out->has_thumbnail_image = 1;
      ++i;
      out->thumbnail_image = CGLTF_PTRINDEX(cgltf_image, cgltf_json_to_int(tokens + i, json_chunk));
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "version") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->version);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "copyrightInformation") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->copyright_information);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "contactInformation") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->contact_information);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "allowAntisocialOrHateUsage") == 0)
    {
      ++i;
      out->allow_antisocial_or_hate_usage = cgltf_json_to_bool(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "allowExcessivelySexualUsage") == 0)
    {
      ++i;
      out->allow_excessively_sexual_usage = cgltf_json_to_bool(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "allowExcessivelyViolentUsage") == 0)
    {
      ++i;
      out->allow_excessively_violent_usage = cgltf_json_to_bool(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "allowPoliticalOrReligiousUsage") == 0)
    {
      ++i;
      out->allow_political_or_religious_usage = cgltf_json_to_bool(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "avatarPermission") == 0)
    {
      ++i;
      out->avatar_permission = cgltf_vrm_string_to_meta_avatar_permission(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "commercialUsage") == 0)
    {
      ++i;
      out->commercial_usage = cgltf_vrm_string_to_meta_commercial_usage(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "creditNotation") == 0)
    {
      ++i;
      out->credit_notation = cgltf_vrm_string_to_meta_credit_notation(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "modification") == 0)
    {
      ++i;
      out->modification = cgltf_vrm_string_to_meta_modification(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "allowRedistribution") == 0)
    {
      ++i;
      out->allow_redistribution = cgltf_json_to_bool(tokens + i, json_chunk);
      ++i;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_vrm.meta.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_first_person(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_first_person* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens+i, json_chunk, "meshAnnotations") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_first_person_mesh_annotation), (void**)&out->mesh_annotations, &out->mesh_annotations_count);

      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->mesh_annotations_count; ++k)
      {
        cgltf_size nElems = tokens[i].size;
        ++i;

        for (cgltf_size l = 0; l < nElems; ++l)
        {
          if (cgltf_json_strcmp(tokens + i, json_chunk, "node") == 0)
          {
            ++i;
            out->mesh_annotations[k].node = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
            ++i;
          }
          else if (cgltf_json_strcmp(tokens + i, json_chunk, "type") == 0)
          {
            ++i;
            out->mesh_annotations[k].type = cgltf_vrm_string_to_first_person_mesh_annotation(tokens + i, json_chunk);
            ++i;
          }
        }
        if (i < 0)
        {
          return i;
        }
      }
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_vrm.firstPerson.")
    }

    if (i < 0)
    {
      return i;
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_expression_morph_target_binds(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_expression_morph_target_bind* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "index") == 0)
    {
      ++i;
      out->index = cgltf_json_to_int(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "node") == 0)
    {
      ++i;
      out->node = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "weight") == 0)
    {
      ++i;
      out->weight = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_expressions_dict(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_expression** out, cgltf_size *out_size, char const* tag)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  *out_size = tokens[i].size;
  *out = (cgltf_vrm_expression*)cgltf_calloc(options, sizeof(cgltf_vrm_expression), *out_size);
  ++i;

  if (!*out)
  {
    return CGLTF_ERROR_NOMEM;
  }

  for (cgltf_size j = 0; j < *out_size; ++j)
  {
    cgltf_vrm_expression *expression = &(*out)[j];

    CGLTF_CHECK_KEY(tokens[i]);
    i = cgltf_parse_json_string(options, tokens, i, json_chunk, &expression->name);

    cgltf_size nElems = tokens[i].size;
    ++i;

    for (cgltf_size k = 0; k < nElems; ++k)
    {
      CGLTF_CHECK_KEY(tokens[i]);

      if (cgltf_json_strcmp(tokens+i, json_chunk, "isBinary") == 0)
      {
        ++i;
        expression->is_binary = cgltf_json_to_bool(tokens + i, json_chunk);
        ++i;
      }
      else if (cgltf_json_strcmp(tokens+i, json_chunk, "overrideBlink") == 0)
      {
        ++i;
        expression->override_blink = cgltf_vrm_string_to_expression_override(tokens + i, json_chunk);
        ++i;
      }
      else if (cgltf_json_strcmp(tokens+i, json_chunk, "overrideMouth") == 0)
      {
        ++i;
        expression->override_mouth = cgltf_vrm_string_to_expression_override(tokens + i, json_chunk);
        ++i;
      }
      else if (cgltf_json_strcmp(tokens+i, json_chunk, "overrideLookAt") == 0)
      {
        ++i;
        expression->override_look_at = cgltf_vrm_string_to_expression_override(tokens + i, json_chunk);
        ++i;
      }
      else if (cgltf_json_strcmp(tokens+i, json_chunk, "morphTargetBinds") == 0)
      {
        i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_expression_morph_target_bind), (void**)&expression->morph_target_binds, &expression->morph_target_binds_count);
        if (i < 0)
        {
          return i;
        }
        for (cgltf_size l = 0; l < expression->morph_target_binds_count; ++l)
        {
          i = cgltf_vrm_parse_json_expression_morph_target_binds(options, tokens, i, json_chunk, &expression->morph_target_binds[l]);
          if (i < 0)
          {
            return i;
          }
        }
      }
      /*
      else if (cgltf_json_strcmp(tokens+i, json_chunk, "materialColorBinds") == 0)
      {
        // i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_expression_material_color_bind), (void**)&expression->material_color_binds, &outexpression->material_color_binds_count);
      }
      else if (cgltf_json_strcmp(tokens+i, json_chunk, "transformBinds") == 0)
      {
        // i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_expression_texture_transform_bind), (void**)&expression->texture_transform_binds, &expression->texture_transform_binds_count);
      }
      */
      else
      {
        CGLTF_VRM_LOG_SKIPPED(tag)
      }
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_expressions(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_expressions* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);
  memset(out, 0, sizeof(cgltf_vrm_expression));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens+i, json_chunk, "preset") == 0)
    {
      i = cgltf_vrm_parse_json_expressions_dict(options, tokens, i + 1, json_chunk, &out->preset, &out->preset_count, "VRMC_vrm.expressions.preset");
    }
    else if (cgltf_json_strcmp(tokens+i, json_chunk, "custom") == 0)
    {
      i = cgltf_vrm_parse_json_expressions_dict(options, tokens, i + 1, json_chunk, &out->custom, &out->custom_count, "VRMC_vrm.expressions.custom");
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_vrm.expressions.")
    }

    if (i < 0)
    {
      return i;
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_look_at_range_map(jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_look_at_range_map* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "inputMaxValue") == 0)
    {
      ++i;
      out->input_max_value = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "outputScale") == 0)
    {
      ++i;
      out->output_scale = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_vrm.lookAt.rangeMap??")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_look_at(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_look_at* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_look_at));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens + i, json_chunk, "type") == 0)
    {
      ++i;
      out->type = cgltf_vrm_string_to_look_at(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "offsetFromHeadBone") == 0)
    {
      i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->offset_from_head_bone, 3);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "rangeMapHorizontalInner") == 0)
    {
      i = cgltf_vrm_parse_json_look_at_range_map(tokens, i + 1, json_chunk, &out->range_map_horizontal_inner);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "rangeMapHorizontalOuter") == 0)
    {
      i = cgltf_vrm_parse_json_look_at_range_map(tokens, i + 1, json_chunk, &out->range_map_horizontal_outer);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "rangeMapVerticalUp") == 0)
    {
      i = cgltf_vrm_parse_json_look_at_range_map(tokens, i + 1, json_chunk, &out->range_map_vertical_up);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "rangeMapVerticalDown") == 0)
    {
      i = cgltf_vrm_parse_json_look_at_range_map(tokens, i + 1, json_chunk, &out->range_map_vertical_down);
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_vrm.lookAt.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_vrm(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_core* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_core));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens + i, json_chunk, "specVersion") == 0)
    {
      ++i;
      out->spec_version = cgltf_vrm_string_to_spec_version(tokens, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "humanoid") == 0)
    {
      i = cgltf_vrm_parse_json_humanoid(options, tokens, i + 1, json_chunk, &out->humanoid);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "meta") == 0)
    {
      i = cgltf_vrm_parse_json_meta(options, tokens, i + 1, json_chunk, &out->meta);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "firstPerson") == 0)
    {
      i = cgltf_vrm_parse_json_first_person(options, tokens, i + 1, json_chunk, &out->first_person);
      out->has_first_person = 1;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "expressions") == 0)
    {
      i = cgltf_vrm_parse_json_expressions(options, tokens, i + 1, json_chunk, &out->expressions);
      out->has_expressions = 1;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "lookAt") == 0)
    {
      i = cgltf_vrm_parse_json_look_at(options, tokens, i + 1, json_chunk, &out->look_at);
      out->has_look_at = 1;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_vrm.")
    }

    if (i < 0)
    {
      return i;
    }
  }

  return i;
}

/* ----------- VRMC_springBone ----------- */

static
int cgltf_vrm_parse_json_spring_bone_colliders(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_spring_bone_collider* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "node") == 0)
    {
      ++i;
      out->node = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "shape") == 0)
    {
      cgltf_size nElems;

      i += 2;
      out->shape = cgltf_vrm_string_to_spring_bone_collider_shape(tokens + i, json_chunk);
      ++i;

      nElems = tokens[i].size;
      ++i;

      for (cgltf_size k = 0; k < nElems; ++k)
      {
        if (cgltf_json_strcmp(tokens + i, json_chunk, "radius") == 0)
        {
          ++i;
          out->radius = cgltf_json_to_float(tokens + i, json_chunk);
          ++i;
        }
        else if (cgltf_json_strcmp(tokens + i, json_chunk, "offset") == 0)
        {
          i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->offset, 3);
        }
        else if (cgltf_json_strcmp(tokens + i, json_chunk, "tail") == 0)
        {
          i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->tail, 3);
        }
        else
        {
          CGLTF_VRM_LOG_SKIPPED("VRMC_springBone.colliders.shape.")
        }
      }
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_springBone.colliders.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_spring_bone_collider_groups(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_spring_bone_collider_group* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "name") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->name);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliders") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(int), (void**)&out->colliders, &out->colliders_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->colliders_count; ++k)
      {
        out->colliders[k] = cgltf_json_to_int(tokens + i, json_chunk);
        ++i;
      }
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_springBone.colliderGroups.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_spring_bone_spring_joint(jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_spring_bone_spring_joint* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_spring_bone_spring_joint));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "node") == 0)
    {
      ++i;
      out->node = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "dragForce") == 0)
    {
      ++i;
      out->drag_force = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "hitRadius") == 0)
    {
      ++i;
      out->hit_radius = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "stiffness") == 0)
    {
      ++i;
      out->stiffness = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "gravityPower") == 0)
    {
      ++i;
      out->gravity_power = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "gravityDir") == 0)
    {
      i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->gravity_dir, 3);
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_springBone.springJoints.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_spring_bone_springs(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_spring_bone_spring* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "name") == 0)
    {
      i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out->name);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "joints") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_spring_bone_spring_joint), (void**)&out->joints, &out->joints_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->joints_count; ++k)
      {
        i = cgltf_vrm_parse_json_spring_bone_spring_joint(tokens, i, json_chunk, &out->joints[k]);
      }
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliderGroups") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(int), (void**)&out->collider_groups, &out->collider_groups_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->collider_groups_count; ++k)
      {
        out->collider_groups[k] = cgltf_json_to_int(tokens + i, json_chunk);
        ++i;
      }
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "center") == 0)
    {
      ++i;
      out->center = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
      ++i;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_springBone.springs.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_spring_bone(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_spring_bone* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_spring_bone));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens + i, json_chunk, "specVersion") == 0)
    {
      ++i;
      out->spec_version = cgltf_vrm_string_to_spec_version(tokens, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliders") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_spring_bone_collider), (void**)&out->colliders, &out->colliders_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->colliders_count; ++k)
      {
        i = cgltf_vrm_parse_json_spring_bone_colliders(options, tokens, i, json_chunk, &out->colliders[k]);
        if (i < 0)
        {
          return i;
        }
      }
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliderGroups") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_spring_bone_collider_group), (void**)&out->collider_groups, &out->collider_groups_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->collider_groups_count; ++k)
      {
        i = cgltf_vrm_parse_json_spring_bone_collider_groups(options, tokens, i, json_chunk, &out->collider_groups[k]);
        if (i < 0)
        {
          return i;
        }
      }
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "springs") == 0)
    {
      i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_spring_bone_spring), (void**)&out->springs, &out->springs_count);
      if (i < 0)
      {
        return i;
      }
      for (cgltf_size k = 0; k < out->springs_count; ++k)
      {
        i = cgltf_vrm_parse_json_spring_bone_springs(options, tokens, i, json_chunk, &out->springs[k]);
        if (i < 0)
        {
          return i;
        }
      }
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_springBone.")
    }

    if (i < 0)
    {
      return i;
    }
  }

  return i;
}

/* ----------- VRMC_node_constraint ----------- */

static
cgltf_int cgltf_vrm_node_extension_index(cgltf_node* node, char const* extension)
{
  if (node == NULL || extension == NULL)
  {
    return -1;
  }

  for (cgltf_size i = 0; i < node->extensions_count; ++i)
  {
    if (strcmp(node->extensions[i].name, extension) == 0)
    {
      return i;
    }
  }
  return -1;
}

static
cgltf_extension* cgltf_vrm_get_node_extension(cgltf_node* node, char const* extension)
{
  cgltf_int index = cgltf_vrm_node_extension_index(node, extension);
  return (index >= 0) ? &node->extensions[index] : NULL;
}

static
int cgltf_vrm_parse_json_node_constraint(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_node_constraint* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_node_constraint));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens + i, json_chunk, "specVersion") == 0)
    {
      ++i;
      out->spec_version = cgltf_vrm_string_to_spec_version(tokens, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "constraint") == 0)
    {
      i += 2;
      out->type = cgltf_vrm_string_to_node_constraint_type(tokens + i, json_chunk);
      ++i;

      cgltf_size nElems = tokens[i].size;
      ++i;

      for (cgltf_size k = 0; k < nElems; ++k)
      {
        if (cgltf_json_strcmp(tokens + i, json_chunk, "source") == 0)
        {
          ++i;
          out->source = CGLTF_PTRINDEX(cgltf_node, cgltf_json_to_int(tokens + i, json_chunk));
          ++i;
        }
        else if (cgltf_json_strcmp(tokens + i, json_chunk, "weight") == 0)
        {
          ++i;
          out->weight = cgltf_json_to_float(tokens + i, json_chunk);
          ++i;
        }
        else if (cgltf_json_strcmp(tokens + i, json_chunk, "aimAxis") == 0)
        {
          ++i;
          out->axis.aim = cgltf_vrm_string_to_node_constraint_aim_axis(tokens + i, json_chunk);
          ++i;
        }
        else if (cgltf_json_strcmp(tokens + i, json_chunk, "rollAxis") == 0)
        {
          ++i;
          out->axis.roll = cgltf_vrm_string_to_node_constraint_roll_axis(tokens + i, json_chunk);
          ++i;
        }
        else
        {
          CGLTF_VRM_LOG_SKIPPED("VRMC_node_constraint.constraint.")
        }
      }
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_node_constraint.")
    }

    if (i < 0)
    {
      return i;
    }
  }

  return i;
}

/* ----------- VRMC_materials_mtoon ----------- */

static
cgltf_int cgltf_vrm_material_extension_index(cgltf_material* material, char const* extension)
{
  if (material == NULL || extension == NULL)
  {
    return -1;
  }

  for (cgltf_size i = 0; i < material->extensions_count; ++i)
  {
    if (strcmp(material->extensions[i].name, extension) == 0)
    {
      return i;
    }
  }
  return -1;
}

static
cgltf_extension* cgltf_vrm_get_material_extension(cgltf_material* material, char const* extension)
{
  cgltf_int index = cgltf_vrm_material_extension_index(material, extension);
  return (index >= 0) ? &material->extensions[index] : NULL;
}

static
int cgltf_vrm_parse_json_mtoon_texture_info(jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_mtoon_texture_info* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_mtoon_texture_info));

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "index") == 0)
    {
      ++i;
      out->index = cgltf_json_to_int(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "texCoord") == 0)
    {
      ++i;
      out->tex_coord = cgltf_json_to_int(tokens + i, json_chunk);
      ++i;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_materials_mtoon.textureInfo.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_mtoon_shading_shift_texture_info(jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_mtoon_shading_shift_texture_info* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_mtoon_shading_shift_texture_info));

  cgltf_size size = tokens[i].size;
  ++i;

  for (cgltf_size j = 0; j < size; ++j)
  {
    if (cgltf_json_strcmp(tokens + i, json_chunk, "index") == 0)
    {
      ++i;
      out->index = cgltf_json_to_int(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "texCoord") == 0)
    {
      ++i;
      out->tex_coord = cgltf_json_to_int(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "scale") == 0)
    {
      ++i;
      out->scale = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_materials_mtoon.shadingShiftTextureInfo.")
    }
  }

  return i;
}

static
int cgltf_vrm_parse_json_material_mtoon(cgltf_options* options, jsmntok_t const* tokens, int i, uint8_t const* json_chunk, cgltf_vrm_mtoon* out)
{
  CGLTF_CHECK_TOKTYPE(tokens[i], JSMN_OBJECT);

  memset(out, 0, sizeof(cgltf_vrm_mtoon));

  int size = tokens[i].size;
  ++i;

  for (int j = 0; j < size; ++j)
  {
    CGLTF_CHECK_KEY(tokens[i]);

    if (cgltf_json_strcmp(tokens + i, json_chunk, "specVersion") == 0)
    {
      ++i;
      out->spec_version = cgltf_vrm_string_to_spec_version(tokens, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "transparentWithZWrite") == 0)
    {
      ++i;
      out->transparent_with_z_write = cgltf_json_to_bool(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "renderQueueOffsetNumber") == 0)
    {
      ++i;
      out->render_queue_offset_number = cgltf_json_to_int(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "shadeColorFactor") == 0)
    {
      i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->shade_color_factor, 3);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "shadingShiftFactor") == 0)
    {
      ++i;
      out->shading_shift_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "shadingToonyFactor") == 0)
    {
      ++i;
      out->shading_toony_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "shadeMultiplyTexture") == 0)
    {
      i = cgltf_vrm_parse_json_mtoon_texture_info(tokens, i + 1, json_chunk, &out->shade_multiply_texture);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "shadingShiftTexture") == 0)
    {
      i = cgltf_vrm_parse_json_mtoon_shading_shift_texture_info(tokens, i + 1, json_chunk, &out->shading_shift_texture);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "giEqualizationFactor") == 0)
    {
      ++i;
      out->gi_equalization_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "matcapFactor") == 0)
    {
      i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->matcap_factor, 3);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "matcapTexture") == 0)
    {
      i = cgltf_vrm_parse_json_mtoon_texture_info(tokens, i + 1, json_chunk, &out->matcap_texture);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "parametricRimColorFactor") == 0)
    {
      i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->parametric_rim_color_factor, 3);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "parametricRimFresnelPowerFactor") == 0)
    {
      ++i;
      out->parametric_rim_fresnel_power_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "parametricRimLiftFactor") == 0)
    {
      ++i;
      out->parametric_rim_lift_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "rimMultiplyTexture") == 0)
    {
      i = cgltf_vrm_parse_json_mtoon_texture_info(tokens, i + 1, json_chunk, &out->rim_multiply_texture);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "rimLightingMixFactor") == 0)
    {
      ++i;
      out->rim_lighting_mix_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "outlineWidthMode") == 0)
    {
      ++i;
      out->outline_width_mode = cgltf_vrm_string_to_mtoon_outline_width_mode(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "outlineWidthFactor") == 0)
    {
      ++i;
      out->outline_width_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "outlineWidthMultiplyTexture") == 0)
    {
      i = cgltf_vrm_parse_json_mtoon_texture_info(tokens, i + 1, json_chunk, &out->outline_width_multiply_texture);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "outlineColorFactor") == 0)
    {
      i = cgltf_parse_json_float_array(tokens, i + 1, json_chunk, out->outline_color_factor, 3);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "outlineLightingMixFactor") == 0)
    {
      ++i;
      out->outline_lighting_mix_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "uvAnimationMaskTexture") == 0)
    {
      i = cgltf_vrm_parse_json_mtoon_texture_info(tokens, i + 1, json_chunk, &out->uv_animation_mask_texture);
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "uvAnimationScrollXSpeedFactor") == 0)
    {
      ++i;
      out->uv_animation_scroll_x_speed_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "uvAnimationScrollYSpeedFactor") == 0)
    {
      ++i;
      out->uv_animation_scroll_y_speed_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else if (cgltf_json_strcmp(tokens + i, json_chunk, "uvAnimationRotationSpeedFactor") == 0)
    {
      ++i;
      out->uv_animation_rotation_speed_factor = cgltf_json_to_float(tokens + i, json_chunk);
      ++i;
    }
    else
    {
      CGLTF_VRM_LOG_SKIPPED("VRMC_materials_mtoon.")
    }

    if (i < 0)
    {
      return i;
    }
  }

  return i;
}

/* -------------------------------------------------------------------------- */

static
int cgltf_vrm_fixup_pointers(cgltf_data const* gltf, cgltf_vrm_data* vrm)
{
  cgltf_vrm_core *vrmc = &vrm->core;

  /* VRMC_vrm.humanoid */
  for (cgltf_size i = 0; i < vrmc->humanoid.human_bones_count; ++i)
  {
    CGLTF_PTRFIXUP(vrmc->humanoid.human_bones[i].node, gltf->nodes, gltf->nodes_count);
  }

  /* VRMC_vrm.meta */
  if (vrmc->meta.has_thumbnail_image)
  {
    CGLTF_PTRFIXUP(vrmc->meta.thumbnail_image, gltf->images, gltf->images_count);
  }

  /* VRMC_vrm.firstPerson */
  for (cgltf_size i = 0; i < vrmc->first_person.mesh_annotations_count; ++i)
  {
    cgltf_vrm_first_person_mesh_annotation *mesh_annotation = &vrmc->first_person.mesh_annotations[i];
    CGLTF_PTRFIXUP(mesh_annotation->node, gltf->nodes, gltf->nodes_count);
  }

  /* VRMC_vrm.expressions */
  for (cgltf_size i = 0; i < vrmc->expressions.preset_count; ++i)
  {
    cgltf_vrm_expression *preset = &vrmc->expressions.preset[i];
    for (cgltf_size j = 0; j < preset->morph_target_binds_count; ++j)
    {
      CGLTF_PTRFIXUP(preset->morph_target_binds[j].node, gltf->nodes, gltf->nodes_count);
    }
  }
  for (cgltf_size i = 0; i < vrmc->expressions.custom_count; ++i)
  {
    cgltf_vrm_expression *custom = &vrmc->expressions.custom[i];
    for (cgltf_size j = 0; j < custom->morph_target_binds_count; ++j)
    {
      CGLTF_PTRFIXUP(custom->morph_target_binds[j].node, gltf->nodes, gltf->nodes_count);
    }
  }

  if (vrm->has_spring_bone)
  {
    cgltf_vrm_spring_bone *sb = &vrm->spring_bone;

    /* VRMC_springBone.colliders */
    for (cgltf_size i = 0; i < sb->colliders_count; ++i)
    {
      CGLTF_PTRFIXUP(sb->colliders[i].node, gltf->nodes, gltf->nodes_count);
    }

    /* VRMC_springBone.springs */
    for (cgltf_size i = 0; i < sb->springs_count; ++i)
    {
      CGLTF_PTRFIXUP(sb->springs[i].center, gltf->nodes, gltf->nodes_count);

      for (cgltf_size j = 0; j < sb->springs[i].joints_count; ++j)
      {
        CGLTF_PTRFIXUP(sb->springs[i].joints[j].node, gltf->nodes, gltf->nodes_count);
      }
    }
  }

  /* VRMC_node_constraint */
  for (cgltf_size i = 0; i < vrm->extended_nodes_count; ++i)
  {
    cgltf_vrm_extended_node* node = &vrm->extended_nodes[i];

    if (node->has_node_constraint)
    {
      CGLTF_PTRFIXUP(node->node_constraint.source, gltf->nodes, gltf->nodes_count);
    }
  }

  return 0;
}

/* -------------------------------------------------------------------------- */

#define CGLTF_VRM_FREE(vrm, data) if (data) (vrm)->memory.free_func((vrm)->memory.user_data, data)

/* [incomplete] */
void cgltf_vrm_free(cgltf_vrm_data *vrm)
{
  if (!vrm)
  {
    return;
  }

  cgltf_vrm_core *vrmc = &vrm->core;

  if (vrmc->humanoid.human_bones_count > 0)
  {
    for (cgltf_size i = 0; i < vrmc->humanoid.human_bones_count; ++i)
    {
      CGLTF_VRM_FREE(vrm, vrmc->humanoid.human_bones[i].name);
    }
    CGLTF_VRM_FREE(vrm, vrmc->humanoid.human_bones);
  }

  CGLTF_VRM_FREE(vrm, vrmc->meta.name);
  CGLTF_VRM_FREE(vrm, vrmc->meta.version);
  CGLTF_VRM_FREE(vrm, vrmc->meta.license_url);
  CGLTF_VRM_FREE(vrm, vrmc->meta.copyright_information);
  CGLTF_VRM_FREE(vrm, vrmc->meta.contact_information);
  for (cgltf_size i = 0; i < vrmc->meta.authors_count; ++i)
  {
    CGLTF_VRM_FREE(vrm, vrmc->meta.authors[i]);
  }
  CGLTF_VRM_FREE(vrm, vrmc->meta.authors);

  if (vrmc->expressions.preset_count > 0)
  {
    for (cgltf_size i = 0; i < vrmc->expressions.preset_count; ++i)
    {
      cgltf_vrm_expression *expression = &vrmc->expressions.preset[i];
      CGLTF_VRM_FREE(vrm, expression->name);

      if (expression->morph_target_binds_count > 0)
      {
        CGLTF_VRM_FREE(vrm, expression->morph_target_binds);
      }
    }
    CGLTF_VRM_FREE(vrm, vrmc->expressions.preset);
  }

  if (vrmc->expressions.custom_count > 0)
  {
    for (cgltf_size i = 0; i < vrmc->expressions.custom_count; ++i)
    {
      cgltf_vrm_expression *expression = &vrmc->expressions.custom[i];
      CGLTF_VRM_FREE(vrm, expression->name);

      if (expression->morph_target_binds_count > 0)
      {
        CGLTF_VRM_FREE(vrm, expression->morph_target_binds);
      }
    }
    CGLTF_VRM_FREE(vrm, vrmc->expressions.custom);
  }

  if (vrm->has_spring_bone)
  {
    cgltf_vrm_spring_bone *sb = &vrm->spring_bone;

    for (cgltf_size i = 0; i < sb->collider_groups_count; ++i)
    {
      CGLTF_VRM_FREE(vrm, sb->collider_groups[i].name);
      CGLTF_VRM_FREE(vrm, sb->collider_groups[i].colliders);
    }
    CGLTF_VRM_FREE(vrm, sb->collider_groups);
  }
}

#undef CGLTF_VRM_FREE

cgltf_result cgltf_vrm_parse_init(cgltf_options *options, char* json_chunk, jsmntok_t** tokens)
{
  const size_t size = strlen(json_chunk);

  jsmn_parser parser = { 0, 0, 0 };

  if (options->json_token_count == 0)
  {
    int token_count = jsmn_parse(&parser, (const char*)json_chunk, size, NULL, 0);
    if (token_count <= 0)
    {
      return cgltf_result_invalid_json;
    }

    options->json_token_count = token_count;
  }

  *tokens = (jsmntok_t*)options->memory.alloc_func(options->memory.user_data, sizeof(jsmntok_t) * (options->json_token_count + 1));
  if (!*tokens)
  {
    return cgltf_result_out_of_memory;
  }

  jsmn_init(&parser);

  int token_count = jsmn_parse(&parser, (const char*)json_chunk, size, *tokens, options->json_token_count);
  if (token_count <= 0)
  {
    options->memory.free_func(options->memory.user_data, *tokens);
    return cgltf_result_invalid_json;
  }
  (*tokens)[token_count].type = JSMN_UNDEFINED;

  return cgltf_result_success;
}

cgltf_result cgltf_vrm_parse_cgltf_data(cgltf_options const* options, cgltf_data const* gltf, cgltf_vrm_data* vrm)
{
  jsmntok_t* tokens = NULL;
  cgltf_options fixed_options;

  if (options == NULL)
  {
    return cgltf_result_invalid_options;
  }

  fixed_options = *options;
  if (fixed_options.memory.alloc_func == NULL)
  {
    fixed_options.memory.alloc_func = &cgltf_default_alloc;
  }
  if (fixed_options.memory.free_func == NULL)
  {
    fixed_options.memory.free_func = &cgltf_default_free;
  }

  memset(vrm, 0, sizeof(cgltf_vrm_data));
  vrm->memory = fixed_options.memory; /**/

  /* --- Generic Extensions --- */

  for (cgltf_size i = 0; i < gltf->data_extensions_count; ++i)
  {
    cgltf_extension* ext = &gltf->data_extensions[i];
    char* json_chunk = ext->data;

    cgltf_result result = cgltf_vrm_parse_init(&fixed_options, json_chunk, &tokens);
    if (result != cgltf_result_success)
    {
      if (tokens != NULL)
      {
        fixed_options.memory.free_func(fixed_options.memory.user_data, tokens);
      }
      return result;
    }

    if (strcmp(ext->name, "VRMC_vrm") == 0)
    {
      cgltf_vrm_parse_json_vrm(&fixed_options, tokens, 0, (uint8_t const*)json_chunk, &vrm->core);
    }
    else if (strcmp(ext->name, "VRMC_springBone") == 0)
    {
      cgltf_vrm_parse_json_spring_bone(&fixed_options, tokens, 0, (uint8_t const*)json_chunk, &vrm->spring_bone);
      vrm->has_spring_bone = true;
    }

    fixed_options.memory.free_func(fixed_options.memory.user_data, tokens);
    tokens = NULL;
  }

  /* --- Node extensions --- */

  vrm->extended_nodes_count = gltf->nodes_count;
  vrm->extended_nodes = (cgltf_vrm_extended_node*)cgltf_calloc(&fixed_options, sizeof(cgltf_vrm_extended_node), vrm->extended_nodes_count);

  for (cgltf_size i = 0; i < gltf->nodes_count; ++i)
  {
    cgltf_extension *ext = cgltf_vrm_get_node_extension(&gltf->nodes[i], "VRMC_node_constraint");

    if (ext != NULL)
    {
      cgltf_vrm_extended_node *node = &vrm->extended_nodes[i];
      char* json_chunk = ext->data;

      cgltf_result result = cgltf_vrm_parse_init(&fixed_options, json_chunk, &tokens);
      if (result != cgltf_result_success)
      {
        if (tokens != NULL)
        {
          fixed_options.memory.free_func(fixed_options.memory.user_data, tokens);
        }
        return result;
      }

      cgltf_vrm_parse_json_node_constraint(&fixed_options, tokens, 0, (uint8_t const*)json_chunk, &node->node_constraint);
      node->has_node_constraint = true;

      fixed_options.memory.free_func(fixed_options.memory.user_data, tokens);
      tokens = NULL;
    }
  }

  /* --- Material extensions --- */

  vrm->extended_materials_count = gltf->materials_count;
  vrm->extended_materials = (cgltf_vrm_extended_material*)cgltf_calloc(&fixed_options, sizeof(cgltf_vrm_extended_material), vrm->extended_materials_count);

  for (cgltf_size i = 0; i < gltf->materials_count; ++i)
  {
    cgltf_extension *ext = cgltf_vrm_get_material_extension(&gltf->materials[i], "VRMC_materials_mtoon");

    if (ext != NULL)
    {
      cgltf_vrm_extended_material *mat = &vrm->extended_materials[i];
      char* json_chunk = ext->data;

      cgltf_result result = cgltf_vrm_parse_init(&fixed_options, json_chunk, &tokens);
      if (result != cgltf_result_success)
      {
        if (tokens != NULL)
        {
          fixed_options.memory.free_func(fixed_options.memory.user_data, tokens);
        }
        return result;
      }

      cgltf_vrm_parse_json_material_mtoon(&fixed_options, tokens, 0, (uint8_t const*)json_chunk, &mat->mtoon);
      mat->has_mtoon = true;

      fixed_options.memory.free_func(fixed_options.memory.user_data, tokens);
      tokens = NULL;
    }
  }

  /* --------------------------- */

  if (cgltf_vrm_fixup_pointers(gltf, vrm) < 0)
  {
    cgltf_vrm_free(vrm);
    return cgltf_result_invalid_gltf;
  }

  return cgltf_result_success;
}

/*
cgltf_result cgltf_vrm_parse_file(cgltf_options const* options, char const* filename, cgltf_vrm_data ** out_data)
{
  return cgltf_result_success;
}

cgltf_result cgltf_vrm_parse(cgltf_options const* options, void const* data, cgltf_size size, cgltf_vrm_data** out_data)
{
  return cgltf_result_success;
}
*/

#undef CGLTF_VRM_JSON_LOG
#undef CGLTF_VRM_JSON_SKIP
#undef CGLTF_VRM_LOG_SKIPPED
#undef CGLTF_VRM_RET_STRING_TYPE

#endif /* CGLTF_IMPLEMENTATION */

/*
-------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Thibault Coppex

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
-------------------------------------------------------------------------------
 */