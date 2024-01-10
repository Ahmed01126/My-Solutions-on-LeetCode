int calculateInfectionTime(struct TreeNode* root, int start, int isStartNode, int *maxi) {
    if (root == NULL) return 0;

    if (root->val == start && isStartNode) {
        *maxi = (*maxi > calculateInfectionTime(root, start, 0, maxi) - 1) ? *maxi : calculateInfectionTime(root, start, 0, maxi) - 1;
        return -1;
    }

    int leftHeight = calculateInfectionTime(root->left, start, isStartNode, maxi);
    int rightHeight = calculateInfectionTime(root->right, start, isStartNode, maxi);

    if (leftHeight < 0 || rightHeight < 0) {
        *maxi = (*maxi > abs(leftHeight) + abs(rightHeight)) ? *maxi : abs(leftHeight) + abs(rightHeight);
        return (leftHeight < rightHeight) ? leftHeight - 1 : rightHeight - 1;
    }

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int amountOfTime(struct TreeNode* root, int start) {
    int maxi = -2147483648; // INT_MIN
    int height = calculateInfectionTime(root, start, 1, &maxi);
    return maxi;
}