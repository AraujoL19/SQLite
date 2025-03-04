CREATE TABLE `input` (
  `input_id` integer PRIMARY KEY,
  `cortisol_exp_parameters` json,
  `simulation_gender` varchar(255),
  `initial_conditions` json
);

CREATE TABLE `simulation` (
  `simulation_id` integer PRIMARY KEY,
  `output_id` integer,
  `time_days` integer,
  `simulation_status` text
);

CREATE TABLE `model` (
  `model_id` integer PRIMARY KEY,
  `model_description` text,
  `model_version` integer
);

CREATE TABLE `output` (
  `output_id` integer PRIMARY KEY,
  `model_id` integer,
  `input_id` integer,
  `results` text
);

ALTER TABLE `output` ADD FOREIGN KEY (`input_id`) REFERENCES `input` (`input_id`);

ALTER TABLE `output` ADD FOREIGN KEY (`output_id`) REFERENCES `simulation` (`output_id`);

ALTER TABLE `output` ADD FOREIGN KEY (`model_id`) REFERENCES `model` (`model_id`);
