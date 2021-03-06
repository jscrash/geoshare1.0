#ifndef _GS2_H
#define _GS2_H

/* extra include file for My stuff... Since Julian has gs.h locked. */

#define SHAREDMEM /* turn on use of shared memory */

#ifdef SHAREDMEM
#  define GSInitMem gs_init_pool (0, 0)
#  define GSMalloc  gs_alloc
#  define GSFree    gs_free
#  define GSTermMem gs_term_pool ()
#else
#  define GSInitMem 
#  define GSMalloc  malloc
#  define GSFree    free
#  define GSTermMem
#endif


typedef char **GSTCP_t;

typedef enum {
  GS_STYPE_UNKNOWN = 0,
  GS_STYPE_AMPLITUDE_STATS,
  GS_STYPE_ATTRIBUTE_ITEM,
  GS_STYPE_CARTO_PROJECTION,
  GS_STYPE_CONTACT,
  GS_STYPE_CONTEXT_INFO,
  GS_STYPE_CONTEXT_RQMTS,
  GS_STYPE_CONTEXT_TOKEN,
  GS_STYPE_CONTOUR,
  GS_STYPE_DEPTH,
  GS_STYPE_DISTANCE,
  GS_STYPE_ELEVATION,
  GS_STYPE_ELEVATION_REF,
  GS_STYPE_EXECUTIVE,
  GS_STYPE_EXTENTS,
  GS_STYPE_FAULT_SURFACE,
  GS_STYPE_FAULT_TRACE,
  GS_STYPE_FAULT_TRACE_SET,
  GS_STYPE_GRID,
  GS_STYPE_LEGAL,
  GS_STYPE_LINE_INTERSECTION,
  GS_STYPE_LITHOSTRAT_CODES,
  GS_STYPE_LITHOSTRAT_CODE_DESC,
  GS_STYPE_LITHOSTRAT,
  GS_STYPE_LOG_PASS,
  GS_STYPE_LOG_RUN,
  GS_STYPE_LOG_SERVICE,
  GS_STYPE_LOG_TRACE,
  GS_STYPE_MAP,
  GS_STYPE_MAP_ANNOTATION,
  GS_STYPE_MAP_LOCATION,
  GS_STYPE_MAP_OBJECTS,
  GS_STYPE_MAP_POINT,
  GS_STYPE_MAP_POLYLINE,
  GS_STYPE_MAP_SYMBOL,
  GS_STYPE_MEASUREMENT,
  GS_STYPE_MUD_RESISTIVITY,
  GS_STYPE_PROCESSING_HISTORY,
  GS_STYPE_RECEIVER_CONTEXT,
  GS_STYPE_RECEIVER_RQMTS,
  GS_STYPE_RECEIVER_SPECS,
  GS_STYPE_REQUIREMENT,
  GS_STYPE_RESISTIVITY,
  GS_STYPE_SEGMENT,
  GS_STYPE_SEISMIC_CLASS,
  GS_STYPE_SEISMIC_DATA_POINT,
  GS_STYPE_SEISMIC_LINE,
  GS_STYPE_SEISMIC_LINE_HDR,
  GS_STYPE_SEISMIC_LOCATION_3D,
  GS_STYPE_SEISMIC_LOC_2D,
  GS_STYPE_SEISMIC_SURFACE,
  GS_STYPE_SEISMIC_SURVEY,
  GS_STYPE_SEISMIC_TRACE,
  GS_STYPE_SEISMIC_TRANSDUCER,
  GS_STYPE_SEISMIC_VELOCITY,
  GS_STYPE_STATUS_RETURN,
  GS_STYPE_STATUS_VECTOR,
  GS_STYPE_STRATIGRAPHIC_COLUMN,
  GS_STYPE_STRUCTURE,
  GS_STYPE_SURFACE_ATTRIBUTE,
  GS_STYPE_SURFACE_GEOMETRY,
  GS_STYPE_SURFACE_INTERSECTION,
  GS_STYPE_SURFACE_REPRESENTATION,
  GS_STYPE_SURFACE_SET,
  GS_STYPE_SURFACE_SURFACE_INTERSECTION,
  GS_STYPE_SURFACE_TRACE,
  GS_STYPE_TEMPERATURE,
  GS_STYPE_TIME,
  GS_STYPE_UNIT,
  GS_STYPE_VELOCITY,
  GS_STYPE_VELOCITY_PAIR,
  GS_STYPE_VERSION,
  GS_STYPE_WEIGHT,
  GS_STYPE_WELL_ATTRIBUTE,
  GS_STYPE_WELL_CORE,
  GS_STYPE_WELL_FIELD,
  GS_STYPE_WELL_HDR,
  GS_STYPE_WELL_MARKER,
  GS_STYPE_WELL_PRODUCTION,
  GS_STYPE_WELL_REMARKS,
  GS_STYPE_WELL_TEST_HDR,
  GS_STYPE_WELL_TIE,
  GS_STYPE_WELL_TUBULARS,
  GS_STYPE_XYZ_DATA,
  GS_STYPE_XYZ_POINT,
  GS_STYPE_ZONES,
  GS_STYPE_ZONE_DEFINITION,
  GS_STYPE_ZONE_NAME,
  GS_STYPE_ZONE_VALUE,
  GS_STYPE_ZONE_VARIABLE,
  GS_STYPE_ZONE_VARIABLE_DEFINITION,
  GS_STYPE_TCB
} GSAllStructType_t ;

enum
{
  GSE_NO_WELL_IDENTIFIER,
  GSE_INVALID_STRING_FORMAT
} ;

/*  Bit mask indicating data types */

#define GS_UNKNOWN_DTYPE  (1<<0)
#define GS_WELL_DTYPE     (1<<1)
#define GS_SEISMIC_DTYPE  (1<<2)
#define GS_LEASE_DTYPE    (1<<3)
#define GS_CULTURE_DTYPE  (1<<4)
#define GS_GRAPHIC_DTYPE  (1<<5)
#define GS_CODES_DTYPE    (1<<6)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* The following is a proposed change to GSContextInformation_t  */
/*								 */
typedef struct			/*				 */
{				/*				 */
  GSString_t keyword;		/*				 */
  GSString_t value;		/*				 */
} GSContextValue_t;		/*				 */
/*								 */
typedef struct			/*				 */
{				/*				 */
  GSVector_t context_value;	/*				 */
} GSContextInfo_t ;		/*				 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef VARCHAR
#  define VARCHAR struct varchar_struct
   VARCHAR {
      short len;
      char  *arr;
   } ;

#  define V_LEN(x)       (x.len)
#  define V_STRING(x)    (x.arr)
#  define V_SETZERO(x)   (V_STRING(x)[V_LEN(x)] = 0)
#  define V_SETLEN(x)    (V_LEN(x) = strlen( (char *)V_STRING(x) ))
#  define V_FROMC(d, s)  {strcpy((char *)V_STRING(d), (char *)s); V_SETLEN(d); }
#  define V_FROMV(d, s)  {V_SETZERO(s); strcpy((char *)d, (char *)V_STRING(s));}
#  define V_CLEAR(x)     V_FROMC (x, "")
#  define V_V_TO_C(d, s) V_FROMV (d, s)
#  define V_C_TO_V(d, s) V_FROMC (d, s)
#endif

#include "prototypes.h"
#endif
