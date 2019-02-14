from cili.util import *
from cili.cleanup import *

# Collect data frames from the example files
samps, events = samps, events = load_eyelink_dataset("tests/data/mono250.asc")

#print(samps)


# Clean the data using cili's built-in functions
samps = interp_eyelink_blinks(samps, events, interp_fields=['pup_l'])
samps = interp_zeros(samps, interp_fields=['pup_l'])
samps = butterworth_series(samps, fields=['pup_l'])

# Convert
print(samps)
