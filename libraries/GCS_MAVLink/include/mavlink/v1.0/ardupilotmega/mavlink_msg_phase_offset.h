// MESSAGE PHASE_OFFSET PACKING

#define MAVLINK_MSG_ID_PHASE_OFFSET 188

typedef struct __mavlink_phase_offset_t
{
 uint16_t phase_offset; ///< Phase Offset
} mavlink_phase_offset_t;

#define MAVLINK_MSG_ID_PHASE_OFFSET_LEN 2
#define MAVLINK_MSG_ID_188_LEN 2

#define MAVLINK_MSG_ID_PHASE_OFFSET_CRC 35
#define MAVLINK_MSG_ID_188_CRC 35



#define MAVLINK_MESSAGE_INFO_PHASE_OFFSET { \
	"PHASE_OFFSET", \
	1, \
	{  { "phase_offset", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_phase_offset_t, phase_offset) }, \
         } \
}


/**
 * @brief Pack a phase_offset message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param phase_offset Phase Offset
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_phase_offset_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t phase_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PHASE_OFFSET_LEN];
	_mav_put_uint16_t(buf, 0, phase_offset);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#else
	mavlink_phase_offset_t packet;
	packet.phase_offset = phase_offset;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PHASE_OFFSET;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PHASE_OFFSET_LEN, MAVLINK_MSG_ID_PHASE_OFFSET_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
}

/**
 * @brief Pack a phase_offset message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param phase_offset Phase Offset
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_phase_offset_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t phase_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PHASE_OFFSET_LEN];
	_mav_put_uint16_t(buf, 0, phase_offset);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#else
	mavlink_phase_offset_t packet;
	packet.phase_offset = phase_offset;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PHASE_OFFSET;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PHASE_OFFSET_LEN, MAVLINK_MSG_ID_PHASE_OFFSET_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
}

/**
 * @brief Encode a phase_offset struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param phase_offset C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_phase_offset_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_phase_offset_t* phase_offset)
{
	return mavlink_msg_phase_offset_pack(system_id, component_id, msg, phase_offset->phase_offset);
}

/**
 * @brief Encode a phase_offset struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param phase_offset C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_phase_offset_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_phase_offset_t* phase_offset)
{
	return mavlink_msg_phase_offset_pack_chan(system_id, component_id, chan, msg, phase_offset->phase_offset);
}

/**
 * @brief Send a phase_offset message
 * @param chan MAVLink channel to send the message
 *
 * @param phase_offset Phase Offset
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_phase_offset_send(mavlink_channel_t chan, uint16_t phase_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PHASE_OFFSET_LEN];
	_mav_put_uint16_t(buf, 0, phase_offset);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, buf, MAVLINK_MSG_ID_PHASE_OFFSET_LEN, MAVLINK_MSG_ID_PHASE_OFFSET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, buf, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
#else
	mavlink_phase_offset_t packet;
	packet.phase_offset = phase_offset;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, (const char *)&packet, MAVLINK_MSG_ID_PHASE_OFFSET_LEN, MAVLINK_MSG_ID_PHASE_OFFSET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, (const char *)&packet, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PHASE_OFFSET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_phase_offset_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t phase_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, phase_offset);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, buf, MAVLINK_MSG_ID_PHASE_OFFSET_LEN, MAVLINK_MSG_ID_PHASE_OFFSET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, buf, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
#else
	mavlink_phase_offset_t *packet = (mavlink_phase_offset_t *)msgbuf;
	packet->phase_offset = phase_offset;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, (const char *)packet, MAVLINK_MSG_ID_PHASE_OFFSET_LEN, MAVLINK_MSG_ID_PHASE_OFFSET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PHASE_OFFSET, (const char *)packet, MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PHASE_OFFSET UNPACKING


/**
 * @brief Get field phase_offset from phase_offset message
 *
 * @return Phase Offset
 */
static inline uint16_t mavlink_msg_phase_offset_get_phase_offset(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a phase_offset message into a struct
 *
 * @param msg The message to decode
 * @param phase_offset C-struct to decode the message contents into
 */
static inline void mavlink_msg_phase_offset_decode(const mavlink_message_t* msg, mavlink_phase_offset_t* phase_offset)
{
#if MAVLINK_NEED_BYTE_SWAP
	phase_offset->phase_offset = mavlink_msg_phase_offset_get_phase_offset(msg);
#else
	memcpy(phase_offset, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PHASE_OFFSET_LEN);
#endif
}
