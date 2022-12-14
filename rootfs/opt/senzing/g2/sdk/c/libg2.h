/**********************************************************************************
 © Copyright Senzing, Inc. 2017-2022
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIBG2_H
#define LIBG2_H

/* Platform specific function export header */
#if defined(_WIN32)
  #define _DLEXPORT __declspec(dllexport)
#else
#include <stddef.h>
  #define _DLEXPORT __attribute__ ((visibility ("default")))
#endif


#ifdef __cplusplus 
extern "C"
{
#endif


  /* flags for exporting entity data  */
  #define G2_EXPORT_INCLUDE_RESOLVED static_cast<long long>( 1LL << 0 )  // we should include entities with "resolved" relationships
  #define G2_EXPORT_INCLUDE_POSSIBLY_SAME static_cast<long long>( 1LL << 1 )  // we should include entities with "possibly same" relationships
  #define G2_EXPORT_INCLUDE_POSSIBLY_RELATED static_cast<long long>( 1LL << 2 )  // we should include entities with "possibly related" relationships
  #define G2_EXPORT_INCLUDE_NAME_ONLY static_cast<long long>( 1LL << 3 )  // we should include entities with "name only" relationships
  #define G2_EXPORT_INCLUDE_DISCLOSED static_cast<long long>( 1LL << 4 )  // we should include entities with "disclosed" relationships
  #define G2_EXPORT_INCLUDE_SINGLETONS static_cast<long long>( 1LL << 5 )  // we should include singleton entities
  #define G2_EXPORT_INCLUDE_ALL_ENTITIES (G2_EXPORT_INCLUDE_RESOLVED | G2_EXPORT_INCLUDE_SINGLETONS)
  #define G2_EXPORT_INCLUDE_ALL_RELATIONSHIPS (G2_EXPORT_INCLUDE_POSSIBLY_SAME | G2_EXPORT_INCLUDE_POSSIBLY_RELATED | G2_EXPORT_INCLUDE_NAME_ONLY | G2_EXPORT_INCLUDE_DISCLOSED)

  /* flags for outputting entity relation data  */
  #define G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS static_cast<long long>( 1LL << 6 )  // include "possibly same" relationships on entities
  #define G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS static_cast<long long>( 1LL << 7 )  // include "possibly related" relationships on entities
  #define G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS static_cast<long long>( 1LL << 8 )  // include "name only" relationships on entities
  #define G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS static_cast<long long>( 1LL << 9 )  // include "disclosed" relationships on entities
  #define G2_ENTITY_INCLUDE_ALL_RELATIONS (G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS | G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS | G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS | G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS)

  /* flags for outputting entity feature data  */
  #define G2_ENTITY_INCLUDE_ALL_FEATURES static_cast<long long>( 1LL << 10 )  // include all features for entities
  #define G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES static_cast<long long>( 1LL << 11 )  // include only representative features on entities

  /* flags for getting extra information about an entity  */
  #define G2_ENTITY_INCLUDE_ENTITY_NAME static_cast<long long>( 1LL << 12 )  // include the name of the entity
  #define G2_ENTITY_INCLUDE_RECORD_SUMMARY static_cast<long long>( 1LL << 13 )  // include the record summary of the entity
  #define G2_ENTITY_INCLUDE_RECORD_DATA static_cast<long long>( 1LL << 14 )  // include the basic record data for the entity
  #define G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO static_cast<long long>( 1LL << 15 )  // include the record matching info for the entity
  #define G2_ENTITY_INCLUDE_RECORD_JSON_DATA static_cast<long long>( 1LL << 16 )  // include the record json data for the entity
  #define G2_ENTITY_INCLUDE_RECORD_FORMATTED_DATA static_cast<long long>( 1LL << 17 )  // include the record formattted data for the entity
  #define G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS static_cast<long long>( 1LL << 18 )  // include the features identifiers for the records
  #define G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME static_cast<long long>( 1LL << 19 )  // include the name of the related entities
  #define G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO static_cast<long long>( 1LL << 20 )  // include the record matching info of the related entities
  #define G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY static_cast<long long>( 1LL << 21 )  // include the record summary of the related entities
  #define G2_ENTITY_INCLUDE_RELATED_RECORD_DATA static_cast<long long>( 1LL << 22 )  // include the basic record of the related entities

  /* flags for extra feature data  */
  #define G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES static_cast<long long>( 1LL << 23 )  // include internal features
  #define G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS static_cast<long long>( 1LL << 24 )  // include statistics on features

  /* flags for finding entity path data  */
  #define G2_FIND_PATH_PREFER_EXCLUDE static_cast<long long>( 1LL << 25 )  // excluded entities are still allowed, but not preferred

  /* flags for including search result feature scores  */
  #define G2_INCLUDE_FEATURE_SCORES static_cast<long long>( 1LL << 26 )  // include feature scores
  #define G2_SEARCH_INCLUDE_STATS static_cast<long long>( 1LL << 27 )  // include statistics from search results
  #define G2_SEARCH_INCLUDE_FEATURE_SCORES (G2_INCLUDE_FEATURE_SCORES)  // include feature scores from search results

  /* flags for searching for entities  */
  #define G2_SEARCH_INCLUDE_RESOLVED (G2_EXPORT_INCLUDE_RESOLVED)
  #define G2_SEARCH_INCLUDE_POSSIBLY_SAME (G2_EXPORT_INCLUDE_POSSIBLY_SAME)
  #define G2_SEARCH_INCLUDE_POSSIBLY_RELATED (G2_EXPORT_INCLUDE_POSSIBLY_RELATED)
  #define G2_SEARCH_INCLUDE_NAME_ONLY (G2_EXPORT_INCLUDE_NAME_ONLY)
  #define G2_SEARCH_INCLUDE_ALL_ENTITIES (G2_SEARCH_INCLUDE_RESOLVED | G2_SEARCH_INCLUDE_POSSIBLY_SAME | G2_SEARCH_INCLUDE_POSSIBLY_RELATED | G2_SEARCH_INCLUDE_NAME_ONLY)

  /* recommended settings */
  #define G2_RECORD_DEFAULT_FLAGS (G2_ENTITY_INCLUDE_RECORD_JSON_DATA) // the recommended default flag values for getting records
  #define G2_ENTITY_DEFAULT_FLAGS (G2_ENTITY_INCLUDE_ALL_RELATIONS | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES | G2_ENTITY_INCLUDE_ENTITY_NAME | G2_ENTITY_INCLUDE_RECORD_SUMMARY | G2_ENTITY_INCLUDE_RECORD_DATA | G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO | G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME | G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY | G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO) // the recommended default flag values for getting entities
  #define G2_ENTITY_BRIEF_DEFAULT_FLAGS (G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO | G2_ENTITY_INCLUDE_ALL_RELATIONS | G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO) // the recommended default flag values for a brief entity result
  #define G2_EXPORT_DEFAULT_FLAGS (G2_EXPORT_INCLUDE_ALL_ENTITIES | G2_EXPORT_INCLUDE_ALL_RELATIONSHIPS | G2_ENTITY_INCLUDE_ALL_RELATIONS | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES | G2_ENTITY_INCLUDE_ENTITY_NAME | G2_ENTITY_INCLUDE_RECORD_DATA | G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO | G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO) // the recommended default flag values for exporting entities
  #define G2_FIND_PATH_DEFAULT_FLAGS (G2_ENTITY_INCLUDE_ALL_RELATIONS | G2_ENTITY_INCLUDE_ENTITY_NAME | G2_ENTITY_INCLUDE_RECORD_SUMMARY | G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO) // the recommended default flag values for finding entity paths
  #define G2_WHY_ENTITY_DEFAULT_FLAGS (G2_ENTITY_DEFAULT_FLAGS | G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS | G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES | G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS | G2_INCLUDE_FEATURE_SCORES) // the recommended default flag values for why-analysis on entities
  #define G2_HOW_ENTITY_DEFAULT_FLAGS (G2_ENTITY_DEFAULT_FLAGS | G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS | G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES | G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS | G2_INCLUDE_FEATURE_SCORES) // the recommended default flag values for how-analysis on entities

  #define G2_SEARCH_BY_ATTRIBUTES_ALL (G2_SEARCH_INCLUDE_ALL_ENTITIES | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES | G2_ENTITY_INCLUDE_ENTITY_NAME | G2_ENTITY_INCLUDE_RECORD_SUMMARY | G2_SEARCH_INCLUDE_FEATURE_SCORES) // the recommended flag values for searching by attributes, returning all matching entities
  #define G2_SEARCH_BY_ATTRIBUTES_STRONG (G2_SEARCH_INCLUDE_RESOLVED | G2_SEARCH_INCLUDE_POSSIBLY_SAME | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES | G2_ENTITY_INCLUDE_ENTITY_NAME | G2_ENTITY_INCLUDE_RECORD_SUMMARY | G2_SEARCH_INCLUDE_FEATURE_SCORES) // the recommended flag values for searching by attributes, returning only strongly matching entities
  #define G2_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL (G2_SEARCH_INCLUDE_ALL_ENTITIES) // return minimal data with all matches
  #define G2_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG (G2_SEARCH_INCLUDE_RESOLVED | G2_SEARCH_INCLUDE_POSSIBLY_SAME ) // return minimal data with only the strongest matches
  #define G2_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS (G2_SEARCH_BY_ATTRIBUTES_ALL) // the recommended default flag values for search-by-attributes


  /**
   * @brief
   * This method will initialize the G2 processing object.  It must be called
   * once per process, prior to any other calls.
   *
   * @param moduleName A name for the processing node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string containing configuration paramters.
   * @param initConfigID Identifier for the configuration to use in initialization.
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT int G2_init(const char *moduleName, const char *iniParams, const int verboseLogging);
  _DLEXPORT int G2_initWithConfigID(const char *moduleName, const char *iniParams, const long long initConfigID, const int verboseLogging);


  /**
   * @brief
   * This method will re-initialize the G2 processing object.
   */
  _DLEXPORT int G2_reinit(const long long initConfigID);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 processing object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT int G2_destroy();


  /**
   * @brief
   * This method may optionally be called to pre-initialize some of the heavier weight
   * internal resources of the G2 engine.
   */
  _DLEXPORT int G2_primeEngine();


  /**
   * @brief
   * This method will send a record for processing in g2. It is a synchronous
   * call, i.e. it will wait until g2 actually processes the record, and then
   * return any response message.
   *
   * @details
   * This version of the process function will check if a response message
   * was returned for the processing of the input message. If so, it will store
   * it in the responseBuf parameter. This method will not throw an exception.
   *
   * @param record An input record to be processed.
   * @param responseBuf After synchronously waiting for the input to
   *        complete its processing, if there is any associated response message
   *        generated from the input, it is stored in this response buffer.
   *        If there was no response message upon successful processing, then
   *        empty string is stored. If an error occurred, an error response is
   *        stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 object is not intitialized. Returns -2 if an 
   *         exception was thrown and caught. 
   */
  _DLEXPORT int G2_process(const char *record);
  _DLEXPORT int G2_processWithInfo(const char *record, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_processWithResponse(const char *record, char *responseBuf, const size_t bufSize);
  _DLEXPORT int G2_processWithResponseResize(const char *record, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief
   * Used for checking specific records.
   */
  _DLEXPORT int G2_checkRecord(const char *record, const char* recordQueryList, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief Process a record contained in the internal redo-queue
   * 
   * @param responseBuf A memory buffer for returning the record that was
   *        processed by this call.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param infoBuf Same as responseBuf. In a success, returns info about the 
            affected entities
   * @param infoBufSize Same as bufSize but for infoBuf
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   */
  _DLEXPORT int G2_processRedoRecord(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT int G2_processRedoRecordWithInfo(const long long flags, char **responseBuf, size_t *bufSize, char **infoBuf, size_t *infoBufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief Retrieve a record contained in the internal redo-queue
   * 
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   */
  _DLEXPORT int G2_getRedoRecord(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief Get the number of records contained in the internal redo-queue
   */
  _DLEXPORT long long G2_countRedoRecords();


  /**
   * @brief
   * This method returns a JSON document that provides basic statistics on
   * the requests made through the G2 object.  It returns things such as the
   * number of records loaded, the duration of processing time, the number of
   * retries made, etc.
   * 
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   */
  _DLEXPORT int G2_stats(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief
   * This method returns a JSON document containing the G2 configuration.
   * 
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @param configID An integer specifying the configID of the config being 
   *        exported.
   */
  _DLEXPORT int G2_exportConfig(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT int G2_exportConfigAndConfigID(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize), long long* configID );


  /**
   * @brief
   * This method returns an identifier for the loaded G2 engine configuration
   * 
   * @param configID The identifier value for the config.
   */
  _DLEXPORT int G2_getActiveConfigID(long long* configID);


  /**
   * @brief
   * This method returns the timestamp of when the entity datastore was last modified.
   * This is a long integer representing number of seconds since 
   * January 1, 1970 12:00am GMT (epoch time)
   * 
   * @param lastModifiedTime The last modified time.
   */
  _DLEXPORT int G2_getRepositoryLastModifiedTime(long long* lastModifiedTime);


  /**
   * @brief
   * This method is used to add entity data into the system.  This adds or
   * updates a single entity observation record, by adding features for the 
   * observation.
   * 
   * @param dataSourceCode The data source for the observation.
   * @param recordID The ID for the record
   * @param jsonData A JSON document containing the attribute information
   *        for the observation.
   * @param loadID The observation load ID for the record, can be NULL and will default to dataSourceCode
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the module transport is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_addRecord(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID);
  _DLEXPORT int G2_addRecordWithReturnedRecordID(const char* dataSourceCode, const char* jsonData, const char *loadID, char *recordIDBuf, const size_t bufSize);
  _DLEXPORT int G2_addRecordWithInfo(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_addRecordWithInfoWithReturnedRecordID(const char* dataSourceCode, const char* jsonData, const char *loadID, const long long flags, char *recordIDBuf, const size_t recordIDBufSize, char **responseBuf, size_t *responseBufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_replaceRecord(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID);
  _DLEXPORT int G2_replaceRecordWithInfo(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief Reevaluate an entity in the database.
   */
  _DLEXPORT int G2_reevaluateRecord(const char* dataSourceCode, const char* recordID, const long long flags);
  _DLEXPORT int G2_reevaluateEntity(const long long entityID, const long long flags);
  _DLEXPORT int G2_reevaluateRecordWithInfo(const char* dataSourceCode, const char* recordID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_reevaluateEntityWithInfo(const long long entityID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to delete observation data from the system.  This
   * removes a single entity observation record, by removing all of its
   * feature data and the observation itself from all lenses.
   * 
   * @param dataSourceCode The data source for the observation.
   * @param recordID The ID for the record
   * @param loadID The observation load ID for the record, can be NULL and will default to dataSourceCode
   * @param responseBuf A buffer that returns a JSON object that summaries the changes cased by adding the
   *        record. Also contains the recordID.
   * @param bufSize The size of the responseBuf buffer
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_deleteRecord(const char* dataSourceCode, const char* recordID, const char* loadID);
  _DLEXPORT int G2_deleteRecordWithInfo(const char* dataSourceCode, const char* recordID, const char* loadID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method searches for entities that contain attribute information
   * that are relevant to a set of input search attributes.
   * 
   * @param jsonData A JSON document containing the attribute information
   *        to search for
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_searchByAttributes(const char* jsonData, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_searchByAttributes_V2(const char* jsonData, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to retrieve information about a specific resolved 
   * entity.  The information is returned as a JSON document.
   *
   * @param entityID The resolved entity to retrieve information for
   * @param dataSourceCode The data source of the observation to search for
   * @param recordID The record ID of the observation to search for
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_getEntityByEntityID(const long long entityID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_getEntityByEntityID_V2(const long long entityID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_getEntityByRecordID(const char* dataSourceCode, const char* recordID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_getEntityByRecordID_V2(const char* dataSourceCode, const char* recordID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to retrieve a stored record.
   * 
   * @param dataSourceCode The data source of the observation to search for
   * @param recordID The record ID of the observation to search for
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_getRecord(const char* dataSourceCode, const char* recordID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_getRecord_V2(const char* dataSourceCode, const char* recordID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to find a relationship path between entities.
   * 
   * @param entityID1 The starting entity of the relationship path
   * @param entityID2 The ending entity of the relationship path
   * @param dataSourceCode1 The data source for the starting record of the relationship path
   * @param recordID1 The record ID for the starting record of the relationship path
   * @param dataSourceCode2 The data source for the ending record of the relationship path
   * @param recordID2 The record ID for the ending record of the relationship path
   * @param maxDegree The maximum degree of relationships to search
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_findPathByEntityID(const long long entityID1, const long long entityID2, const int maxDegree, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathByEntityID_V2(const long long entityID1, const long long entityID2, const int maxDegree, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathByRecordID(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const int maxDegree, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathByRecordID_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const int maxDegree, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to find a relationship path between entities, that excludes
   * a particular set of entities.
   * 
   * @param entityID1 The starting entity of the relationship path
   * @param entityID2 The ending entity of the relationship path
   * @param dataSourceCode1 The data source for the starting record of the relationship path
   * @param recordID1 The record ID for the starting record of the relationship path
   * @param dataSourceCode2 The data source for the ending record of the relationship path
   * @param recordID2 The record ID for the ending record of the relationship path
   * @param maxDegree The maximum degree of relationships to search
   * @param excludedEntities A JSON document identifying the list of entities to
   *        exclude from the path.  
   *        (example:  {"ENTITIES":[{"ENTITY_ID":"6"},{"ENTITY_ID":"11"},{"ENTITY_ID":"9"}]} )
   * @param excludedRecords A JSON document identifying the list of records for
   *        entities to exclude from the path.  
   *        (example:  {"RECORDS":[{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1504"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1507"}]} )
   * @param flags A bit mask specifying control flags, such as 
   *        "G2_FIND_PATH_PREFER_EXCLUDE".  The default and recommended
   *        value is "G2_FIND_PATH_DEFAULT_FLAGS".
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_findPathExcludingByEntityID(const long long entityID1, const long long entityID2, const int maxDegree, const char* excludedEntities, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathExcludingByEntityID_V2(const long long entityID1, const long long entityID2, const int maxDegree, const char* excludedEntities, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathExcludingByRecordID(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const int maxDegree, const char* excludedRecords, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathExcludingByRecordID_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const int maxDegree, const char* excludedRecords, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to find a relationship path between entities, that excludes
   * a particular set of entities, and also requires at least one data source from a
   * set to be part of the path.
   * 
   * @param entityID1 The starting entity of the relationship path
   * @param entityID2 The ending entity of the relationship path
   * @param dataSourceCode1 The data source for the starting record of the relationship path
   * @param recordID1 The record ID for the starting record of the relationship path
   * @param dataSourceCode2 The data source for the ending record of the relationship path
   * @param recordID2 The record ID for the ending record of the relationship path
   * @param maxDegree The maximum degree of relationships to search
   * @param excludedEntities A JSON document identifying the list of entities to
   *        exclude from the path.  
   *        (example:  {"ENTITIES":[{"ENTITY_ID":"6"},{"ENTITY_ID":"11"},{"ENTITY_ID":"9"}]} )
   * @param excludedRecords A JSON document identifying the list of records for
   *        entities to exclude from the path.  
   *        (example:  {"RECORDS":[{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1504"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1507"}]} )
   * @param requiredDsrcs A JSON document identifying the list of data sources to watch for
   *        (example:  {"DATA_SOURCES":["PEOPLE","COMPANIES"]} )
   * @param flags A bit mask specifying control flags, such as 
   *        "G2_FIND_PATH_PREFER_EXCLUDE".  The default and recommended
   *        value is "G2_FIND_PATH_DEFAULT_FLAGS".
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_findPathIncludingSourceByEntityID(const long long entityID1, const long long entityID2, const int maxDegree, const char* excludedEntities, const char* requiredDsrcs, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathIncludingSourceByEntityID_V2(const long long entityID1, const long long entityID2, const int maxDegree, const char* excludedEntities, const char* requiredDsrcs, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathIncludingSourceByRecordID(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const int maxDegree, const char* excludedRecords, const char* requiredDsrcs, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findPathIncludingSourceByRecordID_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const int maxDegree, const char* excludedRecords, const char* requiredDsrcs, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

 
  /**
   * @brief
   * This method is used to find a network of entity relationships, surrounding the paths between
   * a set of entities.
   * 
   * @param entityList A JSON document identifying the list of entities to
   *        find paths between and a network around. 
   *        (example:  {"ENTITIES":[{"ENTITY_ID":"6"},{"ENTITY_ID":"11"},{"ENTITY_ID":"9"}]} )
   * @param recordList A JSON document identifying the list of record entities to
   *        find paths between and a network around. 
   *        (example:  {"RECORDS":[{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1504"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1507"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1510"}]} )
   * @param maxDegree The maximum degree of relationships to search for a path
   * @param buildOutDegree The maximum degree of relationships to include in the network
   *        around each entity
   * @param maxEntities The maximum number of entities to return
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT int G2_findNetworkByEntityID(const char* entityList, const int maxDegree, const int buildOutDegree, const int maxEntities, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findNetworkByEntityID_V2(const char* entityList, const int maxDegree, const int buildOutDegree, const int maxEntities, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findNetworkByRecordID(const char* recordList, const int maxDegree, const int buildOutDegree, const int maxEntities, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findNetworkByRecordID_V2(const char* recordList, const int maxDegree, const int buildOutDegree, const int maxEntities, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method determines what interesting entities exist around a particular resolved entity
   */
  _DLEXPORT int G2_findInterestingEntitiesByEntityID(const long long entityID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_findInterestingEntitiesByRecordID(const char* dataSourceCode, const char* recordID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method determines why records are included in the resolved entity they belong to.
   */
  _DLEXPORT int G2_whyEntityByRecordID(const char* dataSourceCode, const char* recordID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_whyEntityByRecordID_V2(const char* dataSourceCode, const char* recordID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_whyEntityByEntityID(const long long entityID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_whyEntityByEntityID_V2(const long long entityID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method determines how records are related to each other.
   */
  _DLEXPORT int G2_whyRecords(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_whyRecords_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  

  /**
   * @brief
   * This method determines how entities are related to each other.
   */
  _DLEXPORT int G2_whyEntities(const long long entityID1, const long long entityID2, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_whyEntities_V2(const long long entityID1, const long long entityID2, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method gives information on how entities were constructed from their base records.
   */
  _DLEXPORT int G2_howEntityByEntityID(const long long entityID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_howEntityByEntityID_V2(const long long entityID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method gives information on how an entity composed of a given set of records would look
   */
  _DLEXPORT int G2_getVirtualEntityByRecordID(const char* recordList, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2_getVirtualEntityByRecordID_V2(const char* recordList, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This is used to purge all data from an existing repository
   * @return Returns 0 for success, or an appropriate error code.
   */
  _DLEXPORT int G2_purgeRepository();


  /* type definitions for exporting data  */
  typedef void* ExportHandle;


  /**
   * @brief
   * This is used to export entity data from known entities.  This function
   * returns an export-handle that can be read from to get the export data 
   * in JSON format.  The export-handle should be read using the "G2_fetchNext"
   * function, and closed when work is complete. Each output row contains the 
   * exported entity data for a single resolved entity.
   *
   * @param flags A bit mask specifying control flags, such as 
   *        "G2_EXPORT_INCLUDE_SINGLETONS".  The default and recommended
   *        value is "G2_EXPORT_DEFAULT_FLAGS".
   *
   * @return Returns an export handle that the entity data can be read from.
   */
  _DLEXPORT int G2_exportJSONEntityReport(const long long flags, ExportHandle* responseHandle);


  /**
   * @brief
   * This is used to export entity data from known entities.  This function
   * returns an export-handle that can be read from to get the export data 
   * in CSV format.  The export-handle should be read using the "G2_fetchNext"
   * function, and closed when work is complete. The first output row returned 
   * by the export-handle contains the JSON column headers as a string.  Each 
   * following row contains the exported entity data.
   *
   * @param flags A bit mask specifying other control flags, such as 
   *        "G2_EXPORT_INCLUDE_SINGLETONS".  The default and recommended
   *        value is "G2_EXPORT_DEFAULT_FLAGS".
   *
   * @return Returns an export handle that the entity data can be read from.
   */
  _DLEXPORT int G2_exportCSVEntityReport(const char* csvColumnList, const long long flags, ExportHandle* responseHandle);


  /**
   * @brief
   * This function is used to read entity data from an export handle,
   * one data row at a time.
   *
   * @param responseHandle The export handle to retrieve data from
   * @param responseBuf The buffer to write the string data to
   * @param bufSize The size of the response buffer
   *
   * @return Returns a pointer to the buffer if successful, or -1 otherwise
   */
  _DLEXPORT int G2_fetchNext(ExportHandle responseHandle, char *responseBuf, const size_t bufSize);


  /**
   * @brief
   * This function closes an export handle, to clean up system resources.
   */
  _DLEXPORT int G2_closeExport(ExportHandle responseHandle);

  
  /**
   * @brief
   * This function retrieves the last exception thrown in the engine
   * @return number of bytes copied into buffer
   */
  _DLEXPORT int G2_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in the engine
   * @return number of bytes copied into buffer
   */
  _DLEXPORT int G2_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in libG2
   */
  _DLEXPORT void G2_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif /* LIBG2_H */

