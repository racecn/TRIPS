// This file is generated, don't edit it!!

#if !defined(XERCESC_INCLUDE_GUARD_ERRHEADER_XMLExcepts)
#define XERCESC_INCLUDE_GUARD_ERRHEADER_XMLExcepts

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOMError.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// Ignore warning about private constructor
#if defined __GNUC__ && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 5))
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#endif

class XMLExcepts
{
public :
    enum Codes
    {
        NoError                            = 0
      , W_LowBounds                        = 1
      , Scan_CouldNotOpenSource_Warning    = 2
      , W_HighBounds                       = 3
      , F_LowBounds                        = 4
      , Array_BadIndex                     = 5
      , Array_BadNewSize                   = 6
      , AttrList_BadIndex                  = 7
      , AttDef_BadAttType                  = 8
      , AttDef_BadDefAttType               = 9
      , Bitset_BadIndex                    = 10
      , Bitset_NotEqualSize                = 11
      , BufMgr_NoMoreBuffers               = 12
      , BufMgr_BufferNotInPool             = 13
      , CPtr_PointerIsZero                 = 14
      , CM_BinOpHadUnaryType               = 15
      , CM_MustBeMixedOrChildren           = 16
      , CM_NoPCDATAHere                    = 17
      , CM_UnaryOpHadBinType               = 18
      , CM_UnknownCMType                   = 19
      , CM_UnknownCMSpecType               = 20
      , CM_NoParentCSN                     = 21
      , CM_NotValidSpecTypeForNode         = 22
      , DTD_UnknownCreateReason            = 23
      , ElemStack_EmptyStack               = 24
      , ElemStack_StackUnderflow           = 25
      , ElemStack_NoParentPushed           = 26
      , Enum_NoMoreElements                = 27
      , File_CouldNotOpenFile              = 28
      , File_CouldNotGetCurPos             = 29
      , File_CouldNotCloseFile             = 30
      , File_CouldNotSeekToEnd             = 31
      , File_CouldNotSeekToPos             = 32
      , File_CouldNotDupHandle             = 33
      , File_CouldNotReadFromFile          = 34
      , File_CouldNotWriteToFile           = 35
      , File_CouldNotResetFile             = 36
      , File_CouldNotGetSize               = 37
      , File_CouldNotGetBasePathName       = 38
      , Gen_ParseInProgress                = 39
      , Gen_NoDTDValidator                 = 40
      , Gen_CouldNotOpenDTD                = 41
      , Gen_CouldNotOpenExtEntity          = 42
      , Gen_UnexpectedEOF                  = 43
      , HshTbl_ZeroModulus                 = 44
      , HshTbl_BadHashFromKey              = 45
      , HshTbl_NoSuchKeyExists             = 46
      , Mutex_CouldNotDestroy              = 47
      , NetAcc_InternalError               = 48
      , NetAcc_CurlError                   = 49
      , NetAcc_LengthError                 = 50
      , NetAcc_InitFailed                  = 51
      , NetAcc_TargetResolution            = 52
      , NetAcc_CreateSocket                = 53
      , NetAcc_ConnSocket                  = 54
      , NetAcc_WriteSocket                 = 55
      , NetAcc_ReadSocket                  = 56
      , NetAcc_UnsupportedMethod           = 57
      , Pool_ElemAlreadyExists             = 58
      , Pool_InvalidId                     = 59
      , Pool_ZeroModulus                   = 60
      , RdrMgr_ReaderIdNotFound            = 61
      , Reader_BadAutoEncoding             = 62
      , Reader_CouldNotDecodeFirstLine     = 63
      , Reader_NelLsepinDecl               = 64
      , Reader_SrcOfsNotSupported          = 65
      , Reader_EncodingStrRequired         = 66
      , Scan_CouldNotOpenSource            = 67
      , Scan_UnbalancedStartEnd            = 68
      , Scan_BadPScanToken                 = 69
      , Stack_BadIndex                     = 70
      , Stack_EmptyStack                   = 71
      , Str_ZeroSizedTargetBuf             = 72
      , Str_UnknownRadix                   = 73
      , Str_TargetBufTooSmall              = 74
      , Str_StartIndexPastEnd              = 75
      , Str_ConvertOverflow                = 76
      , StrPool_IllegalId                  = 77
      , Trans_Unrepresentable              = 78
      , Trans_BadSrcSeq                    = 79
      , Trans_BadSrcCP                     = 80
      , Trans_BadTrailingSurrogate         = 81
      , Trans_CantCreateCvtrFor            = 82
      , URL_MalformedURL                   = 83
      , URL_UnsupportedProto               = 84
      , URL_UnsupportedProto1              = 85
      , URL_NoProtocolPresent              = 86
      , URL_ExpectingTwoSlashes            = 87
      , URL_RelativeBaseURL                = 88
      , URL_BadPortField                   = 89
      , UTF8_FormatError                   = 90
      , UTF8_Invalid_3BytesSeq             = 91
      , UTF8_Irregular_3BytesSeq           = 92
      , UTF8_Invalid_4BytesSeq             = 93
      , UTF8_Exceeds_BytesLimit            = 94
      , Vector_BadIndex                    = 95
      , Val_InvalidElemId                  = 96
      , Val_CantHaveIntSS                  = 97
      , XMLRec_UnknownEncoding             = 98
      , Parser_Parse1                      = 99
      , Parser_Parse2                      = 100
      , Parser_Next1                       = 101
      , Parser_Next2                       = 102
      , Parser_Next3                       = 103
      , Parser_Next4                       = 104
      , Parser_Factor1                     = 105
      , Parser_Factor2                     = 106
      , Parser_Factor3                     = 107
      , Parser_Factor4                     = 108
      , Parser_Factor5                     = 109
      , Parser_Factor6                     = 110
      , Parser_Atom1                       = 111
      , Parser_Atom2                       = 112
      , Parser_Atom3                       = 113
      , Parser_Atom4                       = 114
      , Parser_Atom5                       = 115
      , Parser_CC1                         = 116
      , Parser_CC2                         = 117
      , Parser_CC3                         = 118
      , Parser_CC5                         = 119
      , Parser_CC6                         = 120
      , Parser_Ope1                        = 121
      , Parser_Ope2                        = 122
      , Parser_Ope3                        = 123
      , Parser_Descape1                    = 124
      , Parser_Descape3                    = 125
      , Parser_Descape4                    = 126
      , Parser_Descape5                    = 127
      , Parser_Process2                    = 128
      , Parser_Quantifier1                 = 129
      , Parser_Quantifier2                 = 130
      , Parser_Quantifier3                 = 131
      , Parser_Quantifier4                 = 132
      , Parser_Quantifier5                 = 133
      , Gen_NoSchemaValidator              = 134
      , SubGrpComparator_NGR               = 135
      , FACET_Invalid_Len                  = 136
      , FACET_Invalid_maxLen               = 137
      , FACET_Invalid_minLen               = 138
      , FACET_NonNeg_Len                   = 139
      , FACET_NonNeg_maxLen                = 140
      , FACET_NonNeg_minLen                = 141
      , FACET_Len_maxLen                   = 142
      , FACET_Len_minLen                   = 143
      , FACET_maxLen_minLen                = 144
      , FACET_Invalid_Tag                  = 145
      , FACET_Len_baseLen                  = 146
      , FACET_minLen_baseminLen            = 147
      , FACET_minLen_basemaxLen            = 148
      , FACET_maxLen_basemaxLen            = 149
      , FACET_maxLen_baseminLen            = 150
      , FACET_Len_baseMinLen               = 151
      , FACET_Len_baseMaxLen               = 152
      , FACET_minLen_baseLen               = 153
      , FACET_maxLen_baseLen               = 154
      , FACET_enum_base                    = 155
      , FACET_Invalid_WS                   = 156
      , FACET_WS_collapse                  = 157
      , FACET_WS_replace                   = 158
      , FACET_Invalid_MaxIncl              = 159
      , FACET_Invalid_MaxExcl              = 160
      , FACET_Invalid_MinIncl              = 161
      , FACET_Invalid_MinExcl              = 162
      , FACET_Invalid_TotalDigit           = 163
      , FACET_Invalid_FractDigit           = 164
      , FACET_PosInt_TotalDigit            = 165
      , FACET_NonNeg_FractDigit            = 166
      , FACET_max_Incl_Excl                = 167
      , FACET_min_Incl_Excl                = 168
      , FACET_maxExcl_minExcl              = 169
      , FACET_maxExcl_minIncl              = 170
      , FACET_maxIncl_minExcl              = 171
      , FACET_maxIncl_minIncl              = 172
      , FACET_TotDigit_FractDigit          = 173
      , FACET_maxIncl_base_maxExcl         = 174
      , FACET_maxIncl_base_maxIncl         = 175
      , FACET_maxIncl_base_minIncl         = 176
      , FACET_maxIncl_base_minExcl         = 177
      , FACET_maxExcl_base_maxExcl         = 178
      , FACET_maxExcl_base_maxIncl         = 179
      , FACET_maxExcl_base_minIncl         = 180
      , FACET_maxExcl_base_minExcl         = 181
      , FACET_minExcl_base_maxExcl         = 182
      , FACET_minExcl_base_maxIncl         = 183
      , FACET_minExcl_base_minIncl         = 184
      , FACET_minExcl_base_minExcl         = 185
      , FACET_minIncl_base_maxExcl         = 186
      , FACET_minIncl_base_maxIncl         = 187
      , FACET_minIncl_base_minIncl         = 188
      , FACET_minIncl_base_minExcl         = 189
      , FACET_maxIncl_notFromBase          = 190
      , FACET_maxExcl_notFromBase          = 191
      , FACET_minIncl_notFromBase          = 192
      , FACET_minExcl_notFromBase          = 193
      , FACET_totalDigit_base_totalDigit   = 194
      , FACET_fractDigit_base_totalDigit   = 195
      , FACET_fractDigit_base_fractDigit   = 196
      , FACET_maxIncl_base_fixed           = 197
      , FACET_maxExcl_base_fixed           = 198
      , FACET_minIncl_base_fixed           = 199
      , FACET_minExcl_base_fixed           = 200
      , FACET_totalDigit_base_fixed        = 201
      , FACET_fractDigit_base_fixed        = 202
      , FACET_maxLen_base_fixed            = 203
      , FACET_minLen_base_fixed            = 204
      , FACET_whitespace_base_fixed        = 205
      , FACET_internalError_fixed          = 206
      , FACET_List_Null_baseValidator      = 207
      , FACET_Union_Null_memberTypeValidators   = 208
      , FACET_Union_Null_baseValidator     = 209
      , FACET_Union_invalid_baseValidatorType   = 210
      , VALUE_NotMatch_Pattern             = 211
      , VALUE_Not_Base64                   = 212
      , VALUE_Not_HexBin                   = 213
      , VALUE_GT_maxLen                    = 214
      , VALUE_LT_minLen                    = 215
      , VALUE_NE_Len                       = 216
      , VALUE_NotIn_Enumeration            = 217
      , VALUE_exceed_totalDigit            = 218
      , VALUE_exceed_fractDigit            = 219
      , VALUE_exceed_maxIncl               = 220
      , VALUE_exceed_maxExcl               = 221
      , VALUE_exceed_minIncl               = 222
      , VALUE_exceed_minExcl               = 223
      , VALUE_WS_replaced                  = 224
      , VALUE_WS_collapsed                 = 225
      , VALUE_Invalid_NCName               = 226
      , VALUE_Invalid_Name                 = 227
      , VALUE_ID_Not_Unique                = 228
      , VALUE_ENTITY_Invalid               = 229
      , VALUE_QName_Invalid                = 230
      , VALUE_NOTATION_Invalid             = 231
      , VALUE_no_match_memberType          = 232
      , VALUE_URI_Malformed                = 233
      , XMLNUM_emptyString                 = 234
      , XMLNUM_WSString                    = 235
      , XMLNUM_2ManyDecPoint               = 236
      , XMLNUM_Inv_chars                   = 237
      , XMLNUM_null_ptr                    = 238
      , XMLNUM_URI_Component_Empty         = 239
      , XMLNUM_URI_Component_for_GenURI_Only   = 240
      , XMLNUM_URI_Component_Invalid_EscapeSequence   = 241
      , XMLNUM_URI_Component_Invalid_Char   = 242
      , XMLNUM_URI_Component_Set_Null      = 243
      , XMLNUM_URI_Component_Not_Conformant   = 244
      , XMLNUM_URI_No_Scheme               = 245
      , XMLNUM_URI_NullHost                = 246
      , XMLNUM_URI_NullPath                = 247
      , XMLNUM_URI_PortNo_Invalid          = 248
      , XMLNUM_DBL_FLT_InvalidType         = 249
      , Regex_Result_Not_Set               = 250
      , Regex_CompactRangesError           = 251
      , Regex_MergeRangesTypeMismatch      = 252
      , Regex_SubtractRangesError          = 253
      , Regex_IntersectRangesError         = 254
      , Regex_ComplementRangesInvalidArg   = 255
      , Regex_InvalidCategoryName          = 256
      , Regex_KeywordNotFound              = 257
      , Regex_BadRefNo                     = 258
      , Regex_UnknownOption                = 259
      , Regex_UnknownTokenType             = 260
      , Regex_RangeTokenGetError           = 261
      , Regex_NotSupported                 = 262
      , Regex_InvalidChildIndex            = 263
      , Regex_RepPatMatchesZeroString      = 264
      , Regex_InvalidRepPattern            = 265
      , NEL_RepeatedCalls                  = 266
      , Out_Of_Memory                      = 267
      , DV_InvalidOperation                = 268
      , XPath_NoAttrSelector               = 269
      , XPath_NoUnionAtStart               = 270
      , XPath_NoMultipleUnion              = 271
      , XPath_MissingAttr                  = 272
      , XPath_ExpectedToken1               = 273
      , XPath_PrefixNoURI                  = 274
      , XPath_NoDoubleColon                = 275
      , XPath_ExpectedStep1                = 276
      , XPath_ExpectedStep2                = 277
      , XPath_ExpectedStep3                = 278
      , XPath_NoForwardSlash               = 279
      , XPath_NoDoubleForwardSlash         = 280
      , XPath_NoForwardSlashAtStart        = 281
      , XPath_NoSelectionOfRoot            = 282
      , XPath_EmptyExpr                    = 283
      , XPath_NoUnionAtEnd                 = 284
      , XPath_InvalidChar                  = 285
      , XPath_TokenNotSupported            = 286
      , XPath_FindSolution                 = 287
      , DateTime_dt_invalid                = 288
      , DateTime_dt_missingT               = 289
      , DateTime_gDay_invalid              = 290
      , DateTime_gMth_invalid              = 291
      , DateTime_gMthDay_invalid           = 292
      , DateTime_dur_invalid               = 293
      , DateTime_dur_Start_dashP           = 294
      , DateTime_dur_noP                   = 295
      , DateTime_dur_DashNotFirst          = 296
      , DateTime_dur_inv_b4T               = 297
      , DateTime_dur_NoTimeAfterT          = 298
      , DateTime_dur_NoElementAtAll        = 299
      , DateTime_dur_inv_seconds           = 300
      , DateTime_date_incomplete           = 301
      , DateTime_date_invalid              = 302
      , DateTime_time_incomplete           = 303
      , DateTime_time_invalid              = 304
      , DateTime_ms_noDigit                = 305
      , DateTime_ym_incomplete             = 306
      , DateTime_ym_invalid                = 307
      , DateTime_year_invalid              = 308
      , DateTime_year_tooShort             = 309
      , DateTime_year_leadingZero          = 310
      , DateTime_ym_noMonth                = 311
      , DateTime_tz_noUTCsign              = 312
      , DateTime_tz_stuffAfterZ            = 313
      , DateTime_tz_invalid                = 314
      , DateTime_year_zero                 = 315
      , DateTime_mth_invalid               = 316
      , DateTime_day_invalid               = 317
      , DateTime_hour_invalid              = 318
      , DateTime_min_invalid               = 319
      , DateTime_second_invalid            = 320
      , DateTime_tz_hh_invalid             = 321
      , PD_EmptyBase                       = 322
      , PD_NSCompat1                       = 323
      , PD_OccurRangeE                     = 324
      , PD_NameTypeOK1                     = 325
      , PD_NameTypeOK2                     = 326
      , PD_NameTypeOK3                     = 327
      , PD_NameTypeOK4                     = 328
      , PD_NameTypeOK5                     = 329
      , PD_NameTypeOK6                     = 330
      , PD_NameTypeOK7                     = 331
      , PD_Recurse1                        = 332
      , PD_Recurse2                        = 333
      , PD_ForbiddenRes1                   = 334
      , PD_ForbiddenRes2                   = 335
      , PD_ForbiddenRes3                   = 336
      , PD_ForbiddenRes4                   = 337
      , PD_NSSubset1                       = 338
      , PD_NSSubset2                       = 339
      , PD_NSRecurseCheckCardinality1      = 340
      , PD_RecurseUnordered                = 341
      , PD_MapAndSum                       = 342
      , PD_InvalidContentType              = 343
      , NodeIDMap_GrowErr                  = 344
      , XSer_ProtoType_Null_ClassName      = 345
      , XSer_ProtoType_NameLen_Dif         = 346
      , XSer_ProtoType_Name_Dif            = 347
      , XSer_InStream_Read_LT_Req          = 348
      , XSer_InStream_Read_OverFlow        = 349
      , XSer_Storing_Violation             = 350
      , XSer_StoreBuffer_Violation         = 351
      , XSer_LoadPool_UppBnd_Exceed        = 352
      , XSer_LoadPool_NoTally_ObjCnt       = 353
      , XSer_Loading_Violation             = 354
      , XSer_LoadBuffer_Violation          = 355
      , XSer_Inv_ClassIndex                = 356
      , XSer_Inv_checkFillBuffer_Size      = 357
      , XSer_Inv_checkFlushBuffer_Size     = 358
      , XSer_Inv_Null_Pointer              = 359
      , XSer_CreateObject_Fail             = 360
      , XSer_ObjCount_UppBnd_Exceed        = 361
      , XSer_GrammarPool_Empty             = 362
      , XSer_GrammarPool_NotEmpty          = 363
      , XSer_StringPool_NotEmpty           = 364
      , XSer_Storer_Loader_Mismatch        = 365
      , VALUE_QName_Invalid2               = 366
      , F_HighBounds                       = 367
      , E_LowBounds                        = 368
      , E_HighBounds                       = 369
    };


private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLExcepts();
};

#if defined __GNUC__ && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 5))
#  pragma GCC diagnostic pop
#endif

XERCES_CPP_NAMESPACE_END

#endif
