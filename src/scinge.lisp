;;;; Scinge. A library for scingineers

(defparameter test_data (list 1 2 3 4 5 6 7 8 9 10))

(defun sum (list) 
  (reduce '+ list))

(defun mean (list) 
  (/ (reduce '+ list) (length list)))

(defun sigma (list) 
  (sqrt (/ (reduce '+ (loop for i in list collect (expt (- (mean list) i) 2))) (length list))))

(defun variance (list) 
  (/ (reduce '+ (loop for i in list collect (expt (- (mean list) i) 2))) (length list)))

(defun delta (start finish)
  (- start finish))

(defun delta_2nd (start1 finish1 start2 finish2)
  (- (delta start1 finish1) (delta start2 finish2)))

(defun velocity (distance time_elapsed)
  (/ distance time_elapsed))

(defun acceleration (distance1 time_elapsed1 distance2 time_elapsed2)
  (- (velocity distance1 time_elapsed1) (velocity distance2 time_elapsed2)))

(defun circumference (radius)
  (* 2 pi radius))

(defun circle_area (radius)
  (* pi (expt radius 2)))

(defun sphere_volume (radius)
  (* (/ 4 3) pi (expt radius 3)))

(defun cone_volume (radius height)
  (/ (* pi radius radius height) 3))

(defun cone_surface_area (radius height)
  (* pi radius (sqrt (+ (expt radius 2) (expt height 2)))))

(defun cylinder_volume (radius height)
  (* pi radius radius height))

(defun cylinder_surface_area (radius height)
  (+ (* 2 pi radius height) (* 2 pi (expt radius 2))))

(defun sphere_surface_area (radius)
  (* 4 pi (expt radius 2)))

(defun triangle_area (base height)
  (/ (* base height) 2))

(print (sigma test_data))
