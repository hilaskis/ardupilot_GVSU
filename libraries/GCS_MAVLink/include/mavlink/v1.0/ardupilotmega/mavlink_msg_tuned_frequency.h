// MESSAGE TUNED_FREQUENCY PACKING

#define MAVLINK_MSG_ID_TUNED_FREQUENCY 187

typedef struct __mavlink_tuned_frequency_t
{
 float tuned_freq; ///< Tuned Frequency
 uint8_t target_system; ///< System ID
} mavlink_tuned_frequency_t;

#define MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN 5
#define MAVLINK_MSG_ID_187_LEN 5

#define MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC 0
#define MAVLINK_MSG_ID_187_CRC 0



#define MAVLINK_MESSAGE_INFO_TUNED_FREQUENCY { \
	"TUNED_FREQUENCY", \
	2, \
	{  { "tuned_freq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tuned_frequency_t, tuned_freq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_tuned_frequency_t, target_system) }, \
         } \
}


/**
 * @brief Pack a tuned_frequency message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param tuned_freq Tuned Frequency
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tuned_frequency_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, float tuned_freq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN];
	_mav_put_float(buf, 0, tuned_freq);
	_mav_put_uint8_t(buf, 4, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#else
	mavlink_tuned_frequency_t packet;
	packet.tuned_freq = tuned_freq;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TUNED_FREQUENCY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN, MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
}

/**
 * @brief Pack a tuned_frequency message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param tuned_freq Tuned Frequency
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tuned_frequency_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,float tuned_freq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN];
	_mav_put_float(buf, 0, tuned_freq);
	_mav_put_uint8_t(buf, 4, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#else
	mavlink_tuned_frequency_t packet;
	packet.tuned_freq = tuned_freq;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TUNED_FREQUENCY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN, MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
}

/**
 * @brief Encode a tuned_frequency struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tuned_frequency C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tuned_frequency_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tuned_frequency_t* tuned_frequency)
{
	return mavlink_msg_tuned_frequency_pack(system_id, component_id, msg, tuned_frequency->target_system, tuned_frequency->tuned_freq);
}

/**
 * @brief Encode a tuned_frequency struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tuned_frequency C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tuned_frequency_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tuned_frequency_t* tuned_frequency)
{
	return mavlink_msg_tuned_frequency_pack_chan(system_id, component_id, chan, msg, tuned_frequency->target_system, tuned_frequency->tuned_freq);
}

/**
 * @brief Send a tuned_frequency message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param tuned_freq Tuned Frequency
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tuned_frequency_send(mavlink_channel_t chan, uint8_t target_system, float tuned_freq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN];
	_mav_put_float(buf, 0, tuned_freq);
	_mav_put_uint8_t(buf, 4, target_system);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, buf, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN, MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, buf, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
#else
	mavlink_tuned_frequency_t packet;
	packet.tuned_freq = tuned_freq;
	packet.target_system = target_system;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, (const char *)&packet, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN, MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, (const char *)&packet, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tuned_frequency_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, float tuned_freq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, tuned_freq);
	_mav_put_uint8_t(buf, 4, target_system);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, buf, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN, MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, buf, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
#else
	mavlink_tuned_frequency_t *packet = (mavlink_tuned_frequency_t *)msgbuf;
	packet->tuned_freq = tuned_freq;
	packet->target_system = target_system;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, (const char *)packet, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN, MAVLINK_MSG_ID_TUNED_FREQUENCY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TUNED_FREQUENCY, (const char *)packet, MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE TUNED_FREQUENCY UNPACKING


/**
 * @brief Get field target_system from tuned_frequency message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tuned_frequency_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field tuned_freq from tuned_frequency message
 *
 * @return Tuned Frequency
 */
static inline float mavlink_msg_tuned_frequency_get_tuned_freq(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a tuned_frequency message into a struct
 *
 * @param msg The message to decode
 * @param tuned_frequency C-struct to decode the message contents into
 */
static inline void mavlink_msg_tuned_frequency_decode(const mavlink_message_t* msg, mavlink_tuned_frequency_t* tuned_frequency)
{
#if MAVLINK_NEED_BYTE_SWAP
	tuned_frequency->tuned_freq = mavlink_msg_tuned_frequency_get_tuned_freq(msg);
	tuned_frequency->target_system = mavlink_msg_tuned_frequency_get_target_system(msg);
#else
	memcpy(tuned_frequency, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TUNED_FREQUENCY_LEN);
#endif
}
