import cv2

img_color = cv2.imread('빛표현.jpg', cv2.IMREAD_UNCHANGED)

cv2.namedWindow('Show')
cv2.imshow('Show', img_color)

# 윈도우를 키보드 입력이 있을 때 까지 띄워놓는다.
cv2.waitKey(0)
cv2.destroyAllWindows()