/******************************************************************************
file:       ZWORD
author:     Robbert de Groot
copyright:  2020, Robbert de Groot
******************************************************************************/

#if !defined(ZWORD_H)
#define      ZWORD_H

/******************************************************************************
include:
******************************************************************************/
#include "grl.h"

/******************************************************************************
constant:
******************************************************************************/
typedef enum
{
   paraTypeNONE,

   paraTypeCOMMENT,

   paraTypeFORMATED,

   paraTypeITEM,

   paraTypeREGULAR,

   paraTypeTITLE_1,
   paraTypeTITLE_2,
   paraTypeTITLE_3,
   paraTypeTITLE_4,
   paraTypeTITLE_5,
   paraTypeTITLE_TOC_1,
   paraTypeTITLE_TOC_2,
   paraTypeTITLE_TOC_3,
   paraTypeTITLE_TOC_4,
   paraTypeTITLE_TOC_5,

   paraTypeSCOPE_FORMATED,
   paraTypeSCOPE_ITEM,
   paraTypeSCOPE_LIST_BULLET,
   paraTypeSCOPE_LIST_NUMBER,
   paraTypeSCOPE_LIST_KEY_VALUE,
   paraTypeSCOPE_TABLE,
   paraTypeSCOPE_TABLE_COLUMN_HEADER,
   paraTypeSCOPE_TABLE_COLUMN_HEADER_NO_BREAK,
   paraTypeSCOPE_TABLE_COLUMN_HEADER_FILL,
   paraTypeSCOPE_TABLE_COLUMN,
   paraTypeSCOPE_TABLE_COLUMN_NO_BREAK,
   paraTypeSCOPE_TABLE_COLUMN_FILL,
   paraTypeSCOPE_TABLE_COLUMN_NUMBER,
   paraTypeSCOPE_TABLE_COLUMN_NUMBER_FILL,
   paraTypeSCOPE_STOP,

   paraTypeTABLE_ROW,
   paraTypeTABLE_COLUMN_HEADER,
   paraTypeTABLE_COLUMN_HEADER_NO_BREAK,
   paraTypeTABLE_COLUMN_HEADER_FILL,
   paraTypeTABLE_COLUMN,
   paraTypeTABLE_COLUMN_NO_BREAK,
   paraTypeTABLE_COLUMN_FILL,
   paraTypeTABLE_COLUMN_NUMBER,
   paraTypeTABLE_COLUMN_NUMBER_FILL,

   paraTypeTABLE_OF_CONTENTS,

   paraTypePAGE_BREAK,

   paraTypeCOUNT
} ParaType;

/******************************************************************************
type:
******************************************************************************/
/******************************************************************************
ParaType containers.
******************************************************************************/
// Same as G_Array ////////////////////////////////////////////////////////////
typedef struct 
{
   GCONTAINER_VAR;

   Gcount                   countTotal;
   Gbit                     isVectorSizing   : 1,
                            isSorted         : 1,
                            isNullEnding     : 1;
   GrlCompareFunc           compareFunc;
   ParaType                *p;
} ParaTypeArray;

#define paraTypeArrayAdd(                ARRAY,        VALUE)                                                       g_ArrayAdd(                (G_Array *) ARRAY,        (Gp *) VALUE) 
#define paraTypeArrayAddAt(              ARRAY, INDEX, VALUE)                                                       g_ArrayAddAt(              (G_Array *) ARRAY, INDEX, (Gp *) VALUE) 
#define paraTypeArrayAddBegin(           ARRAY,        VALUE)                                                       g_ArrayAddBegin(           (G_Array *) ARRAY,        (Gp *) VALUE) 
#define paraTypeArrayAddEnd(             ARRAY,        VALUE)                                                       g_ArrayAddEnd(             (G_Array *) ARRAY,        (Gp *) VALUE) 
#define paraTypeArrayClear(              ARRAY, COUNT, INDEX)                                                       g_ArrayClear(              (G_Array *) ARRAY, COUNT, INDEX) 
#define paraTypeArrayCopy(               ARRAY, COUNT, INDEXSRC, INDEXDST)                                          g_ArrayCopy(               (G_Array *) ARRAY, COUNT, INDEXSRC, INDEXDST) 
#define paraTypeArrayCopyFrom(           ARRAYDST, INDEXDST, ARRAYSRC, COUNT, INDEXSRC)                             g_ArrayCopyFrom(           (G_Array *) ARRAYDST, INDEXDST, (G_Array *) ARRAYSRC, COUNT, INDEXSRC) 
#define paraTypeArrayCreate(                  )                                             (ParaTypeArray *)       g_ArrayCreate(                                ParaTypeArray, ParaType, gbFALSE, NULL, gbTRUE, gbFALSE)
#define paraTypeArrayCreateContent(      ARRAY)                                                                     g_ArrayCreateContent(      (G_Array *) ARRAY, ParaTypeArray, ParaType, gbFALSE, NULL, gbTRUE, gbFALSE)
#define paraTypeArrayDestroy(            ARRAY)                                                                     g_ArrayDestroy(            (G_Array *) ARRAY) 
#define paraTypeArrayDestroyContent(     ARRAY)                                                                     g_ArrayDestroyContent(     (G_Array *) ARRAY) 
#define paraTypeArrayErase(              ARRAY, VALUE)                                                              g_ArrayErase(              (G_Array *) ARRAY, (Gp *) VALUE) 
#define paraTypeArrayEraseAt(            ARRAY, COUNT, INDEX)                                                       g_ArrayEraseAt(            (G_Array *) ARRAY, COUNT, INDEX) 
#define paraTypeArrayEraseBegin(         ARRAY)                                                                     g_ArrayEraseBegin(         (G_Array *) ARRAY) 
#define paraTypeArrayEraseEnd(           ARRAY)                                                                     g_ArrayEraseEnd(           (G_Array *) ARRAY) 
#define paraTypeArrayFind(               ARRAY, VALUE)                                                              g_ArrayFind(               (G_Array *) ARRAY, (Gp *) VALUE) 
#define paraTypeArrayFlush(              ARRAY)                                                                     g_ArrayFlush(              (G_Array *) ARRAY) 
#define paraTypeArrayForEach(            ARRAY, FUNC)                                                               g_ArrayForEach(            (G_Array *) ARRAY, FUNC) 
#define paraTypeArrayGet(                ARRAY)                                            ((ParaType *)            g_ArrayGet(                (G_Array *) ARRAY))
#define paraTypeArrayGetAt(              ARRAY, INDEX)                                     ((ParaType *)            g_ArrayGetAt(              (G_Array *) ARRAY, INDEX))
#define paraTypeArrayGetBegin(           ARRAY)                                            ((ParaType *)            g_ArrayGetBegin(           (G_Array *) ARRAY))
#define paraTypeArrayGetCount(           ARRAY)                                                                     g_ArrayGetCount(           (G_Array *) ARRAY) 
#define paraTypeArrayGetEnd(             ARRAY)                                            ((ParaType *)            g_ArrayGetEnd(             (G_Array *) ARRAY))
#define paraTypeArrayGetSize(            ARRAY)                                                                     g_ArrayGetSize(            (G_Array *) ARRAY) 
#define paraTypeArraySetCount(           ARRAY, COUNT)                                                              g_ArraySetCount(           (G_Array *) ARRAY, COUNT) 
#define paraTypeArraySort(               ARRAY)                                                                     g_ArraySort(               (G_Array *) ARRAY) 
#define paraTypeArraySwap(               ARRAY, INDEXA, INDEXB)                                                     g_ArraySwap(               (G_Array *) ARRAY, INDEXA, INDEXB) 
#define paraTypeArrayUpdateAt(           ARRAY, INDEX, VALUE)                                                       g_ArrayUpdateAt(           (G_Array *) ARRAY, INDEX, (Gp *) VALUE) 

typedef struct 
{
   Gindex          value[10];
} ParaChapter;

typedef struct
{
   ParaType        type;
   Gs             *chapterStr;
   Gs             *str;
} Para;

/******************************************************************************
Para containers.
******************************************************************************/
// Same as G_Array ////////////////////////////////////////////////////////////
typedef struct 
{
   GCONTAINER_VAR;

   Gcount                   countTotal;
   Gbit                     isVectorSizing   : 1,
                            isSorted         : 1,
                            isNullEnding     : 1;
   GrlCompareFunc           compareFunc;
   Para                   **p;
} ParaArray;

#define paraArrayAdd(             ARRAY,        VALUE)                                            g_ArrayAdd(             (G_Array *) ARRAY,        (Gp *) VALUE) 
#define paraArrayAddAt(           ARRAY, INDEX, VALUE)                                            g_ArrayAddAt(           (G_Array *) ARRAY, INDEX, (Gp *) VALUE) 
#define paraArrayAddBegin(        ARRAY,        VALUE)                                            g_ArrayAddBegin(        (G_Array *) ARRAY,        (Gp *) VALUE) 
#define paraArrayAddEnd(          ARRAY,        VALUE)                                            g_ArrayAddEnd(          (G_Array *) ARRAY,        (Gp *) VALUE) 
#define paraArrayClear(           ARRAY, COUNT, INDEX)                                            g_ArrayClear(           (G_Array *) ARRAY, COUNT, INDEX) 
#define paraArrayCopy(            ARRAY, COUNT, INDEXSRC, INDEXDST)                               g_ArrayCopy(            (G_Array *) ARRAY, COUNT, INDEXSRC, INDEXDST) 
#define paraArrayCopyFrom(        ARRAYDST, INDEXDST, ARRAYSRC, COUNT, INDEXSRC)                  g_ArrayCopyFrom(        (G_Array *) ARRAYDST, INDEXDST, (G_Array *) ARRAYSRC, COUNT, INDEXSRC) 
#define paraArrayCreate(               )                                            (ParaArray *) g_ArrayCreate(                             ParaArray, Para *, gbTRUE, NULL, gbTRUE, gbFALSE)
#define paraArrayCreateContent(   ARRAY)                                                          g_ArrayCreateContent(   (G_Array *) ARRAY, ParaArray, Para *, gbTRUE, NULL, gbTRUE, gbFALSE)
#define paraArrayDestroy(         ARRAY)                                                          g_ArrayDestroy(         (G_Array *) ARRAY) 
#define paraArrayDestroyContent(  ARRAY)                                                          g_ArrayDestroyContent(  (G_Array *) ARRAY) 
#define paraArrayErase(           ARRAY, VALUE)                                                   g_ArrayErase(           (G_Array *) ARRAY, (Gp *) VALUE) 
#define paraArrayEraseAt(         ARRAY, COUNT, INDEX)                                            g_ArrayEraseAt(         (G_Array *) ARRAY, COUNT, INDEX) 
#define paraArrayEraseBegin(      ARRAY)                                                          g_ArrayEraseBegin(      (G_Array *) ARRAY) 
#define paraArrayEraseEnd(        ARRAY)                                                          g_ArrayEraseEnd(        (G_Array *) ARRAY) 
#define paraArrayFind(            ARRAY, VALUE)                                                   g_ArrayFind(            (G_Array *) ARRAY, (Gp *) VALUE) 
#define paraArrayFlush(           ARRAY)                                                          g_ArrayFlush(           (G_Array *) ARRAY) 
#define paraArrayForEach(         ARRAY, FUNC)                                                    g_ArrayForEach(         (G_Array *) ARRAY, FUNC) 
#define paraArrayGet(             ARRAY)                                            ((Para **)    g_ArrayGet(             (G_Array *) ARRAY))
#define paraArrayGetAt(           ARRAY, INDEX)                                     ((Para *)     g_ArrayGetAt(           (G_Array *) ARRAY, INDEX))
#define paraArrayGetBegin(        ARRAY)                                            ((Para *)     g_ArrayGetBegin(        (G_Array *) ARRAY))
#define paraArrayGetCount(        ARRAY)                                                          g_ArrayGetCount(        (G_Array *) ARRAY) 
#define paraArrayGetEnd(          ARRAY)                                            ((Para *)     g_ArrayGetEnd(          (G_Array *) ARRAY))
#define paraArrayGetSize(         ARRAY)                                                          g_ArrayGetSize(         (G_Array *) ARRAY) 
#define paraArraySetCount(        ARRAY, COUNT)                                                   g_ArraySetCount(        (G_Array *) ARRAY, COUNT) 
#define paraArraySort(            ARRAY)                                                          g_ArraySort(            (G_Array *) ARRAY) 
#define paraArraySwap(            ARRAY, INDEXA, INDEXB)                                          g_ArraySwap(            (G_Array *) ARRAY, INDEXA, INDEXB) 
#define paraArrayUpdateAt(        ARRAY, INDEX, VALUE)                                            g_ArrayUpdateAt(        (G_Array *) ARRAY, INDEX, (Gp *) VALUE) 

typedef struct
{
   Gfile          *(*FileOpen)(                       Gpath const * const path);
   Gb              (*FileWriteComment)(               Gfile       * const file, Para          const * const para);
   Gb              (*FileWriteFormatHeader)(          Gfile       * const file, Gs            const * const title);
   Gb              (*FileWriteFormatFooter)(          Gfile       * const file);
   Gb              (*FileWriteKeyValue)(              Gfile       * const file, Para          const * const para);
   Gb              (*FileWritePageBreak)(             Gfile       * const file);
   Gb              (*FileWriteParagraph)(             Gfile       * const file, Para          const * const para);
   Gb              (*FileWriteScopeStart)(            Gfile       * const file, ParaType              const type, Gindex const scopeLevel, ParaType const parentType);
   Gb              (*FileWriteScopeStop)(             Gfile       * const file, ParaType              const type, ParaType const parentType);
   Gb              (*FileWriteString)(                Gfile       * const file, Para          const * const para);
   Gb              (*FileWriteStringUnaltered)(       Gfile       * const file, Para          const * const para);
   Gb              (*FileWriteTableHeaderSeparator)(  Gfile       * const file, ParaTypeArray const * const headerList);
   Gb              (*FileWriteTitle)(                 Gfile       * const file, Para          const * const para);
   Gb              (*FileWriteTOC)(                   Gfile       * const file, ParaArray     const * const paraList);
} WriteFunctions;

/******************************************************************************
prototype:
******************************************************************************/
Gs            *GetChapterString(void);

WriteFunctions GetFunctionsHTML(void);
WriteFunctions GetFunctionsMD(  void);
WriteFunctions GetFunctionsRTF( void);

#endif