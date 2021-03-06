
/*

  Copyright (c) 2013 RedBearLab

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

*/

#ifndef MESHSERVICE_H
#define MESHSERVICE_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
 * CONSTANTS
 */

// Profile Parameters
#define TX_MESSAGE_CHAR                                 1
#define RX_MESSAGE_CHAR                                 2
#define JOIN_GROUP_CHAR                                 3
#define LEAVE_GROUP_CHAR				4
#define DEV_NAME_CHAR                                   5  
#define NETWORK_CHAR					6

#define MESSAGE_MAX_LENGTH				26
#define GROUP_ID_LENGTH					2
#ifndef NETWORK_NAME_MAX_SIZE
  #define NETWORK_NAME_LENGTH				20
#else 
  #define NETWORK_NAME_LENGTH                           NETWORK_NAME_MAX_SIZE
#endif
#ifndef NODE_NAME_MAX_SIZE
  #define DEV_NAME_MAX_LENGTH                           20
#else
  #define DEV_NAME_MAX_LENGTH				NODE_NAME_MAX_SIZE
#endif
  
  
// MESH Profile Service UUID                  0x713d-0000-503e4c75ba943148f18d941e     
#define MESH_SERV_UUID                  0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x00,0x00,0x3D,0x71
    
// Char. UUID
#define TX_MESSAGE_UUID                 0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x02,0x00,0x3D,0x71 // For transferring data
#define RX_MESSAGE_UUID                 0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x03,0x00,0x3D,0x71 // For receiving data
#define JOIN_GROUP_UUID                 0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x04,0x00,0x3D,0x71 // For joining a group
#define LEAVE_GROUP_UUID                0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x05,0x00,0x3D,0x71 //For leaving a group

#define DEV_NAME_CHAR_UUID              0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x06,0x00,0x3D,0x71 // For changing device name 
#define NETWORK_NAME_UUID               0x1E,0x94,0x8D,0xF1,0x48,0x31,0x94,0xBA,0x75,0x4C,0x3E,0x50,0x07,0x00,0x3D,0x71 // For reading and changing the network name
      
// MESH Services bit fields                             
#define MESH_SERVICE                    0x00000001 

// Callback events
#define MESSAGE_READY                   1   
#define MESH_RX_NOTI_ENABLED            2
#define MESH_RX_NOTI_DISABLED           3
#define JOIN_GROUP_SET                  4
#define LEAVE_GROUP_SET		        5 
#define DEV_NAME_CHANGED                6
#define NETWORK_SET			7

  
/*********************************************************************
 * TYPEDEFS
 */

// MESH Service callback function
typedef void (*meshServiceCB_t)(uint8 event);

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * Profile Callbacks
 */

// Callback when a characteristic value has changed
typedef NULL_OK void (*meshServiceChange_t)( uint8 paramID );

typedef struct
{
  meshServiceChange_t        pfnMESHServiceChange;  // Called when characteristic value changes
} meshServiceCBs_t;

    

/*********************************************************************
 * API FUNCTIONS 
 */


/*
 * MESH_AddService- Initializes the Simple GATT Profile service by registering
 *          GATT attributes with the GATT server.
 *
 * @param   services - services to add. This is a bit map and can
 *                     contain more than one service.
 */

extern bStatus_t MESH_AddService( uint32 services );

/*
 * MESH_RegisterAppCBs - Registers the application callback function.
 *                    Only call this function once.
 *
 *    appCallbacks - pointer to application callbacks.
 */
extern bStatus_t MESH_RegisterAppCBs( meshServiceCBs_t *appCallbacks );

/*
 * MESH_SetParameter - Set a Simple GATT Profile parameter.
 *
 *    param - Profile parameter ID
 *    len - length of data to right
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate 
 *          data type (example: data type of uint16 will be cast to 
 *          uint16 pointer).
 */
extern bStatus_t MESH_SetParameter( uint8 param, uint8 len, void *value );
  
/*
 * MESH_GetParameter - Get a Simple GATT Profile parameter.
 *
 *    param - Profile parameter ID
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate 
 *          data type (example: data type of uint16 will be cast to 
 *          uint16 pointer).
 */
extern bStatus_t MESH_GetParameter( uint8 param, uint8 *len, void *value );


/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MESHSERVICE_H */