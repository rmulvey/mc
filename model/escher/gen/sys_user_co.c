/*----------------------------------------------------------------------------
 * File:  sys_user_co.c
 *
 * Description:
 * Interface call-outs allow the user to capture execution control of the
 * generated system running on a target.
 * Especially in the deeply embedded software/hardware development world,
 * it may be necessary to tightly interface the xtUML system to the
 * surrounding/containing system. MC-3020 provides callout routines
 * that enable the user to easily interface code generated by the model
 * compiler with other system code. These callout routines are empty when
 * generated by the model compiler. It is up to the user to define
 * additional functionality (if necessary) to be performed at these
 * callout points.
 *--------------------------------------------------------------------------*/

#include "sys_sys_types.h"
#include "sys_user_co.h"
#include "sys_xtumlload.h"

static void read_marking_invocations( void );
static void mark_parse( c_t * );

#ifdef SYS_USER_CO_PRINTF_ON
#include <stdio.h>
#define SYS_USER_CO_PRINTF( s ) printf( s );
#else
#define SYS_USER_CO_PRINTF( s )
#endif

/*
 * UserInitializationCallout
 *
 * This function is invoked at the immediate beginning of application
 * initialization. It is the very first function to be executed at system
 * startup.
 * User supplied implementation of this function should be restricted to
 * things like memory initialization, early hardware duties, etc.
 */
char DTD[256];
void
UserInitializationCalloutf( c_t * argv0 )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserInitializationCallout\n" )
}

extern void Escher_dump_instances( const Escher_DomainNumber_t, const Escher_ClassNumber_t );
/*
 * UserPreOoaInitializationCallout
 *
 * This function is invoked immediately prior to executing any xtUML
 * initialization functions.
 */
void
UserPreOoaInitializationCalloutf( c_t * argv0 )
{
  /* Insert implementation specific code here.  */
  char * a[3] = { 0, 0, 0 };
  Escher_xtUML_load( 3, a );
  read_marking_invocations();
  if ( strstr( argv0, "mcmc" ) ) {
    int i;
    ooaofooa_a0();
    ooaofooa_a1();
    for ( i = 0; i < ooaofooa_MAX_CLASS_NUMBERS; i++ ) {
      if ( 0 || (
           ( i != ooaofooa_TE_VAL_CLASS_NUMBER ) &&
           ! ( ( ooaofooa_V_VAL_CLASS_NUMBER <= i ) && ( i <= ooaofooa_V_SCV_CLASS_NUMBER ) ) &&
           ! ( ( ooaofooa_ACT_BLK_CLASS_NUMBER <= i ) && ( i <= ooaofooa_ACT_BIE_CLASS_NUMBER ) ) &&
           ( i != ooaofooa_TE_SMT_CLASS_NUMBER ) &&
           ( i != ooaofooa_TE_VAR_CLASS_NUMBER ) ) )
      Escher_dump_instances( 0, i );
    }
  }
  SYS_USER_CO_PRINTF( "UserPreOoaInitializationCallout\n" )
}

/*
 * UserPostOoaInitializationCallout
 *
 * This function is invoked immediately after executing any xtUML
 * initialization functions.
 * When this callout function returns, the system dispatcher will allow the
 * xtUML application analysis state models to start consuming events.
 */
void
UserPostOoaInitializationCalloutf( void )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserPostOoaInitializationCallout\n" )
}

/*
 * UserBackgroundProcessingCallout
 *
 * This function is invoked once during each loop execution of the system
 * dispather.
 * It is invoked at the 'top' of the system dispatcher loop, immediately
 * prior to dispatching any xtUML application analysis events.
 */
void
UserBackgroundProcessingCalloutf( void )
{
  /* Insert implementation specific code here.  */
}

/*
 * UserPreShutdownCallout
 *
 * This function is invoked at termination of the system dispatcher, but
 * prior to performing any xtUML application analysis shutdown sequencing.
 */
void
UserPreShutdownCalloutf( void )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserPreShutdownCallout\n" )
}

/*
 * UserPostShutdownCallout
 *
 * This function is invoked immediately before application exit.
 */
void
UserPostShutdownCalloutf( void )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserPostShutdownCallout\n" )
}

/*
 * UserEventCantHappenCallout
 *
 * This function is invoked any time that an event is received that
 * results in a "cant happen" transition.
 */
void
UserEventCantHappenCalloutf(
  const Escher_StateNumber_t current_state,
  const Escher_StateNumber_t next_state,
  const Escher_EventNumber_t event_number )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserEventCantHappenCallout\n" )
}

/*
 * UserEventNoInstanceCallout
 *
 * This function is invoked when we failed to validate the instance
 * to which an event was directed.  This can happen in normal operation
 * when the instance was deleted while the event was in flight (analysis
 * error).
 */
void
UserEventNoInstanceCalloutf(
  const Escher_EventNumber_t event_number )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserEventNoInstanceCallout\n" )
}

/*
 * UserEventFreeListEmptyCallout
 *
 * This function is invoked when an attempt is made to allocate an
 * event, but there are no more left.
 */
void
UserEventFreeListEmptyCalloutf( void )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserEventFreeListEmptyCallout\n" )
}

/*
 * UserEmptyHandleDetectedCallout
 *
 * This function is invoked when an attempt is made to use an instance
 * reference variable (handle) that is null (empty).
 */
void
UserEmptyHandleDetectedCalloutf( c_t * object_keyletters, c_t * s )
{
  fprintf( stderr, "UserEmptyHandleDetectedCallout %s %s.\n", object_keyletters, s );
}

/*
 * UserObjectPoolEmptyCallout
 *
 * This function is invoked when an attempt is made to create an
 * instance of an object, but there are no instances available.
 */
void
UserObjectPoolEmptyCalloutf( const Escher_DomainNumber_t component_number, const Escher_ClassNumber_t class_number )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserObjectPoolEmptyCallout\n" )
}

/*
 * UserNodeListEmptyCallout
 *
 * This function is invoked when an attempt is made to allocate a
 * node, but there are no more left.
 */
void
UserNodeListEmptyCalloutf( void )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserNodeListEmptyCallout\n" )
}

/*
 * UserInterleavedBridgeOverflowCallout
 *
 * This function is invoked when an attempt is made to post too many
 * interleaved bridges.  The depth of this list is defined by
 * SYS_MAX_INTERLEAVED_BRIDGES (unless changed in the archetype).
 */
void
UserInterleavedBridgeOverflowCalloutf( void )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserInterleavedBridgeOverflowCallout\n" )
}

/*
 * UserSelfEventQueueEmptyCallout
 *
 * This function is invoked when the events to self queue is
 * interrogated and found to be empty.
 */
void
UserSelfEventQueueEmptyCalloutf( void )
{
  /* Insert implementation specific code here.  */
}

/*
 * UserNonSelfEventQueueEmptyCallout
 *
 * This function is invoked when the events to instance queue is
 * interrogated and found to be empty.
 */
void
UserNonSelfEventQueueEmptyCalloutf( void )
{
  /* Insert implementation specific code here.  */
}

/*
 * UserPersistenceErrorCallout
 *
 * This function is invoked when the events to instance queue is
 * interrogated and found to be empty.
 */
void
UserPersistenceErrorCalloutf( i_t error_code )
{
  /* Insert implementation specific code here.  */
  SYS_USER_CO_PRINTF( "UserPersistenceErrorCallout\n" )
}

c_t * marking_invocations[ 100 ][ 6 ];
int marking_invocations_index = 0;

static void read_marking_invocations( void )
{
  FILE * m_txt;
  static c_t marking_strings[ 100 ][ ESCHER_SYS_MAX_STRING_LEN ];
  if ( 0 == ( m_txt = fopen( "m.txt", "r" ) ) ) {
    fprintf( stderr, "failed to open m.txt\n" );
  } else {
    while ( 0 != fgets( marking_strings[ marking_invocations_index ], ESCHER_SYS_MAX_STRING_LEN, m_txt ) ) {
      mark_parse( marking_strings[ marking_invocations_index ] );
      marking_invocations_index++;
    }
  }
}

static void mark_parse( c_t * line )
{
  c_t * s = strstr( line, ".invoke " );
  marking_invocations[ marking_invocations_index ][ 0 ] = 0;
  marking_invocations[ marking_invocations_index ][ 1 ] = 0;
  marking_invocations[ marking_invocations_index ][ 2 ] = 0;
  marking_invocations[ marking_invocations_index ][ 3 ] = 0;
  marking_invocations[ marking_invocations_index ][ 4 ] = 0;
  marking_invocations[ marking_invocations_index ][ 5 ] = 0;
  if ( 0 != s ) {
    int pnum;
    s = s + 7; /* Get past ".invoke".  */
    while ( ( 0 != *s ) && ( ' ' == *s ) ) s++; /* Skip blanks.  */
    marking_invocations[ marking_invocations_index ][ 0 ] = s;
    /* Find end of function name.  */
    while ( ( 0 != *s ) && ( '(' != *s ) && ( ' ' != *s ) ) s++;
    if ( 0 == *s ) return;
    while ( ' ' == *s ) *s++ = 0; /* Delimit function name.  */
    if ( '(' == *s ) *s++ = 0; /* Delimit function name.  */
    while ( ' ' == *s ) s++;
    if ( ')' == *s ) return;
    for ( pnum = 1; pnum <= 5; pnum++ ) {
      /* parameter */
      if ( '"' == *s ) {
        s++;
        if ( '"' != *s ) marking_invocations[ marking_invocations_index ][ pnum ] = s;
        while ( ( 0 != *s ) && ( '"' != *s ) ) s++;
        if ( '"' == *s ) *s++ = 0;
      } else {
        if ( '"' != *s ) marking_invocations[ marking_invocations_index ][ pnum ] = s;
        while ( ( 0 != *s ) && ( ',' != *s ) && ( ' ' != *s ) && ( ')' != *s ) ) s++;
      }
      while ( ' ' == *s ) *s++ = 0;
      if ( ')' == *s ) { *s = 0; return; }
      if ( ',' == *s ) *s++ = 0;
      while ( ' ' == *s ) s++;
    }
  }
}

void mark_pass( c_t * );
void mark_pass( c_t * pass )
{ int i;
for ( i = marking_invocations_index - 1; i >= 0; i-- ) {
  ooaofooa_mark_all(
    marking_invocations[ i ][ 0 ],
    marking_invocations[ i ][ 1 ],
    marking_invocations[ i ][ 2 ],
    marking_invocations[ i ][ 3 ],
    marking_invocations[ i ][ 4 ],
    marking_invocations[ i ][ 5 ],
    pass );
}}

