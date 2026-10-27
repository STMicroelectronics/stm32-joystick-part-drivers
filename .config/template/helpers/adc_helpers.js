
/**
 * Calculate the ADC resolution.
 *
 * @param {Object} AdcInstanceConfiguration - ADC instance configuration object containing resolution settings.
 * @returns {number} The ADC resolution calculated as 2 raised to the power of the bit resolution.
 */
function helper_joystick_get_adc_resolution(AdcInstanceConfiguration)
{
  let resolution = "";

  let resolution_bit_nbr = AdcInstanceConfiguration.settings.parameters.basic.resolution;

  resolution = Math.pow(2, resolution_bit_nbr);

  return resolution;
}

/**
 * Extract the peripheral instance name from a dot-separated string
 * For example: "adc12.adc1" -> "adc1"
 *
 * @param {string} full_name Full peripheral path (e.g. "adc12.adc1")
 * @returns {string} Instance name (e.g. "adc1"), or empty string on error
 */
function helper_joystick_get_adc_instance_name(full_name) {
  try {
    console.info(
      `helper_joystick_get_adc_instance_name: full_name=${JSON.stringify(full_name)}`
    );

    if (typeof full_name !== "string" || full_name.length === 0) {
      return "";
    }

    const parts = full_name.split(".");
    const instance_name = parts[parts.length - 1];

    return instance_name || "";
  } catch (e) {
    console.error(`helper_joystick_get_adc_instance_name: ${e}`);
    return "";
  }
}

module.exports = {
  helper_joystick_get_adc_resolution,
  helper_joystick_get_adc_instance_name
}
